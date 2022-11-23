//-----------------------------------------------------------------------------
// File : SampleApp.cpp
// Desc : Sample Application.
// Copyright(c) Project Asura. All right reserved.
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------
#include <SampleApp.h>
#include <asdxMath.h>
#include <asdxLogger.h>


namespace {

#include "../res/shaders/Compiled/SampleVS.inc"
#include "../res/shaders/Compiled/SamplePS.inc"

///////////////////////////////////////////////////////////////////////////////
// Vertex structure
///////////////////////////////////////////////////////////////////////////////
struct Vertex
{
    asdx::Vector3 Position; //!< 位置座標.
    asdx::Vector4 Color;    //!< 頂点カラー.
};

} // namespace


///////////////////////////////////////////////////////////////////////////////
// SampleApp class
///////////////////////////////////////////////////////////////////////////////

//-----------------------------------------------------------------------------
//      コンストラクタです.
//-----------------------------------------------------------------------------
SampleApp::SampleApp()
: asdx::Application(L"d3d11on12", 960, 540, nullptr, nullptr, nullptr)
{
    m_MultiSampleCount      = 1;
    m_MultiSampleQuality    = 0;
    m_SwapChainFormat       = DXGI_FORMAT_R8G8B8A8_UNORM;
    m_DepthStencilFormat    = DXGI_FORMAT_D32_FLOAT;
}

//-----------------------------------------------------------------------------
//      デストラクタです.
//-----------------------------------------------------------------------------
SampleApp::~SampleApp()
{
}

//-----------------------------------------------------------------------------
//      初期化処理です.
//-----------------------------------------------------------------------------
bool SampleApp::OnInit()
{
    // 頂点バッファ初期化.
    {
        const Vertex vertices[] = {
            { asdx::Vector3( 0.0f,  1.0f, 0.0f), asdx::Vector4(1.0f, 0.0f, 0.0f, 1.0f) },
            { asdx::Vector3( 1.0f, -1.0f, 0.0f), asdx::Vector4(0.0f, 1.0f, 0.0f, 1.0f) },
            { asdx::Vector3(-1.0f, -1.0f, 0.0f), asdx::Vector4(0.0f, 0.0f, 1.0f, 1.0f) }
        };

        if (!m_VB.Init(m_pDevice, sizeof(vertices), sizeof(vertices[0]), vertices))
        {
            ELOG("Error : VertexBuffer::Init() Failed.");
            return false;
        }
    }

    // パイプラインステート初期化.
    {
        D3D11_INPUT_ELEMENT_DESC Elements[] = {
            { "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0 },
            { "COLOR", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0 }
        };

        asdx::GraphicsPipelineStateDesc desc;
        desc.VS                 = { SampleVS, sizeof(SampleVS) };
        desc.PS                 = { SamplePS, sizeof(SamplePS) };
        desc.BlendState         = asdx::GetBlendDesc(asdx::BlendState::Opaque);
        desc.DepthStencilState  = asdx::GetDepthStencilDesc(asdx::DepthState::Default);
        desc.RasterizerState    = asdx::GetRasterizerDesc(asdx::RasterizerState::CullBack);
        desc.InputLayout        = { Elements, _countof(Elements) };
        desc.PrimitiveTopology  = D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST;

        if (!m_PSO.Init(m_pDevice, desc))
        {
            ELOG("Error : GraphicsPipelineStateDesc::Init() Failed.");
            return false;
        }
    }

    return true;
}

//-----------------------------------------------------------------------------
//      終了処理です.
//-----------------------------------------------------------------------------
void SampleApp::OnTerm()
{
    m_VB .Term();
    m_PSO.Term();
}

//-----------------------------------------------------------------------------
//      リサイズ時の処理です.
//-----------------------------------------------------------------------------
void SampleApp::OnResize(const asdx::ResizeEventArgs& param)
{
}

//-----------------------------------------------------------------------------
//      描画時の処理です.
//-----------------------------------------------------------------------------
void SampleApp::OnFrameRender()
{
    auto pRTV = m_ColorTarget2D.GetTargetView();
    auto pDSV = m_DepthTarget2D.GetTargetView();

    if (pRTV == nullptr)
    { return; }

    m_pDeviceContext->OMSetRenderTargets(1, &pRTV, pDSV);

    m_pDeviceContext->ClearRenderTargetView(pRTV, m_ClearColor);
    m_pDeviceContext->ClearDepthStencilView(pDSV, D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, 1.0f, 0);

    m_pDeviceContext->RSSetViewports(1, &m_Viewport);
    m_pDeviceContext->RSSetScissorRects(1, &m_ScissorRect);

    auto pVB    = m_VB.GetBuffer();
    auto stride = m_VB.GetStride();
    auto offset = 0u;
    m_pDeviceContext->IASetVertexBuffers(0, 1, &pVB, &stride, &offset);
    m_PSO.Bind(m_pDeviceContext);
    m_pDeviceContext->Draw(3, 0);
    m_PSO.Unbind(m_pDeviceContext);

    Present(0);
}