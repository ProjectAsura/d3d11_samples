//-----------------------------------------------------------------------------
// File : SampleApp.h
// Desc : Sample Application.
// Copyright(c) Project Asura. All right reserved.
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------
#include <asdxApp.h>
#include <asdxBuffer.h>
#include <asdxPipelineState.h>


///////////////////////////////////////////////////////////////////////////////
// SampleApp class
///////////////////////////////////////////////////////////////////////////////
class SampleApp final : public asdx::Application
{
public:
    SampleApp();
    ~SampleApp();

private:
    asdx::VertexBuffer          m_VB;
    asdx::GraphicsPipelineState m_PSO;

    bool OnInit() override;
    void OnTerm() override;
    void OnFrameRender() override;
    void OnResize(const asdx::ResizeEventArgs& param) override;
};