﻿//-----------------------------------------------------------------------------
// File : asdxBuffer.h
// Desc : Buffer Module.
// Copyright(c) Project Asura. All right reserved.
//-----------------------------------------------------------------------------
#pragma once

//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------
#include <d3d11.h>
#include <asdxRef.h>


namespace asdx {

///////////////////////////////////////////////////////////////////////////////
// VertexBuffer class
///////////////////////////////////////////////////////////////////////////////
class VertexBuffer
{
    //=========================================================================
    // list of friend classes and methods.
    //=========================================================================
    /* NOTHING */

public:
    //=========================================================================
    // public variables.
    //=========================================================================
    /* NOTHING */

    //=========================================================================
    // public methods.
    //=========================================================================

    //-------------------------------------------------------------------------
    //! @brief      コンストラクタです.
    //-------------------------------------------------------------------------
    VertexBuffer();

    //-------------------------------------------------------------------------
    //! @brief      デストラクタです.
    //-------------------------------------------------------------------------
    ~VertexBuffer();

    //-------------------------------------------------------------------------
    //! @brief      初期化処理を行います.
    //!
    //! @param[in]      pDevice         デバイスです.
    //! @param[in]      size            バッファサイズです.
    //! @param[in]      stride          1頂点あたりのデータサイズを取得します.
    //! @param[in]      pInitData       初期化データです.
    //! @param[in]      isDynamic       動的にする場合は true を， 静的にする場合は false を指定します.
    //! @param[in]      isSRV           シェーダリソースビューを作成する場合は true を指定します.
    //! @retval true    初期化に成功.
    //! @retval false   初期化に失敗.
    //-------------------------------------------------------------------------
    bool Init(
        ID3D11Device*   pDevice,
        size_t          size, 
        size_t          stride,
        const void*     pInitData,
        bool            isDynamic   = false,
        bool            isSRV       = false);

    //-------------------------------------------------------------------------
    //! @brief      終了処理を行います.
    //-------------------------------------------------------------------------
    void Term();

    //-------------------------------------------------------------------------
    //! @brief      バッファを取得します.
    //!
    //! @return     バッファを返却します.
    //-------------------------------------------------------------------------
    ID3D11Buffer* const GetBuffer() const;

    //-------------------------------------------------------------------------
    //! @brief      シェーダリソースビューを取得します.
    //!
    //! @return     シェーダリソースビューを返却します.
    //-------------------------------------------------------------------------
    ID3D11ShaderResourceView* const GetShaderResource() const;

    //-------------------------------------------------------------------------
    //! @brief      アロー演算子です.
    //-------------------------------------------------------------------------
    ID3D11Buffer* const operator-> () const;

    //-------------------------------------------------------------------------
    //! @brief      1頂点あたりのデータサイズを取得します.
    //-------------------------------------------------------------------------
    uint32_t GetStride() const;

private:
    //=========================================================================
    // private variables.
    //=========================================================================
    RefPtr<ID3D11Buffer>                m_Buffer;   //!< バッファです.
    RefPtr<ID3D11ShaderResourceView>    m_SRV;      //!< シェーダリソースビューです.
    uint32_t                            m_Stride;   //!< 1頂点あたりのサイズです.

    //=========================================================================
    // private methods.
    //=========================================================================
    /* NOTHING */
};

///////////////////////////////////////////////////////////////////////////////
// IndexBuffer class
///////////////////////////////////////////////////////////////////////////////
class IndexBuffer
{
    //=========================================================================
    // list of friend classes and methods.
    //=========================================================================
    /* NOTHING */

public:
    //=========================================================================
    // public variables.
    //=========================================================================
    /* NOTHING */

    //=========================================================================
    // public methods.
    //=========================================================================

    //-------------------------------------------------------------------------
    //! @brief      コンストラクタです.
    //-------------------------------------------------------------------------
    IndexBuffer();

    //-------------------------------------------------------------------------
    //! @brief      デストラクタです.
    //-------------------------------------------------------------------------
    ~IndexBuffer();

    //-------------------------------------------------------------------------
    //! @brief      初期化処理を行います.
    //!
    //! @param[in]      pDevice         デバイスです.
    //! @param[in]      size            バッファサイズです.
    //! @param[in]      pInitData       初期化データです.
    //! @param[in]      isDynamic       動的にする場合は true, 静的にする場合は false を指定.
    //! @retval true    初期化に成功.
    //! @retval false   初期化に失敗.
    //-------------------------------------------------------------------------
    bool Init(ID3D11Device* pDevice, size_t size, const uint32_t* pInitData, bool isDynamic = false);

    //-------------------------------------------------------------------------
    //! @brief      終了処理を行います.
    //-------------------------------------------------------------------------
    void Term();

    //-------------------------------------------------------------------------
    //! @brief      バッファを取得します.
    //!
    //! @return     バッファを返却します.
    //-------------------------------------------------------------------------
    ID3D11Buffer* const GetBuffer() const;

    //-------------------------------------------------------------------------
    //! @brieff     シェーダリソースビューを取得します.
    //!
    //! @return     シェーダリソースビューを返却します.
    //-------------------------------------------------------------------------
    ID3D11ShaderResourceView* const GetShaderResource() const;

    //-------------------------------------------------------------------------
    //! @brief      アロー演算子です.
    //-------------------------------------------------------------------------
    ID3D11Buffer* const operator -> () const;

private:
    //=========================================================================
    // private variables.
    //=========================================================================
    RefPtr<ID3D11Buffer>                m_Buffer;   //!< バッファです.
    RefPtr<ID3D11ShaderResourceView>    m_SRV;      //!< シェーダリソースビューです.

    //=========================================================================
    // private methods.
    //=========================================================================
    /* NOTHING */
};

///////////////////////////////////////////////////////////////////////////////
// ConstantBuffer class
///////////////////////////////////////////////////////////////////////////////
class ConstantBuffer
{
    //=========================================================================
    // list of friend classes and methods.
    //=========================================================================
    /* NOTHING */

public:
    //=========================================================================
    // public variables.
    //=========================================================================
    /* NOTHING */

    //=========================================================================
    // public methods.
    //=========================================================================

    //-------------------------------------------------------------------------
    //! @brief      コンストラクタです.
    //-------------------------------------------------------------------------
    ConstantBuffer();

    //-------------------------------------------------------------------------
    //! @brief      デストラクタです.
    //-------------------------------------------------------------------------
    ~ConstantBuffer();

    //-------------------------------------------------------------------------
    //! @brief      初期化処理を行います.
    //!
    //! @param[in]      pDevice     デバイスです.
    //! @param[in]      size        バッファサイズです.
    //! @retval true    初期化に成功.
    //! @retval false   初期化に失敗.
    //-------------------------------------------------------------------------
    bool Init(ID3D11Device* pDevice, size_t size, bool mappable = false);

    //-------------------------------------------------------------------------
    //! @brief      終了処理を行います.
    //-------------------------------------------------------------------------
    void Term();

    //-------------------------------------------------------------------------
    //! @brief      バッファを取得します.
    //!
    //! @return     バッファを返却します.
    //-------------------------------------------------------------------------
    ID3D11Buffer* const GetBuffer() const;

    //-------------------------------------------------------------------------
    //! @brief      アロー演算子です.
    //-------------------------------------------------------------------------
    ID3D11Buffer* const operator -> () const;

private:
    //=========================================================================
    // private variables.
    //=========================================================================
    RefPtr<ID3D11Buffer>    m_Buffer;       //!< バッファです.

    //=========================================================================
    // private methods.
    //=========================================================================
    /* NOTHING */
};

///////////////////////////////////////////////////////////////////////////////
// StructuredBuffer class
///////////////////////////////////////////////////////////////////////////////
class StructuredBuffer
{
    //=========================================================================
    // list of friend classes and methods.
    //=========================================================================
    /* NOTHING */

public:
    //=========================================================================
    // public variables.
    //=========================================================================
    /* NOTHING */

    //=========================================================================
    // public methods.
    //=========================================================================

    //-------------------------------------------------------------------------
    //! @brief      コンストラクタです.
    //-------------------------------------------------------------------------
    StructuredBuffer();

    //-------------------------------------------------------------------------
    //! @brief      デストラクタです.
    //-------------------------------------------------------------------------
    ~StructuredBuffer();

    //-------------------------------------------------------------------------
    //! @brief      初期化処理を行います.
    //!
    //! @param[in]      pDevice         デバイスです.
    //! @param[in]      size            バッファサイズです.
    //! @paran[in]      stride          ストライドです.
    //! @param[in]      pInitData       初期化データです.
    //! @param[in]      uav             アンオーダードアクセスビューとして有効にする場合は true.
    //! @retval true    初期化に成功.
    //! @retval false   初期化に失敗.
    //-------------------------------------------------------------------------
    bool Init(ID3D11Device* pDevice, uint32_t size, uint32_t stride, const void* pInitData, bool uav = false);

    //-------------------------------------------------------------------------
    //! @brief      終了処理です.
    //-------------------------------------------------------------------------
    void Term();

    //-------------------------------------------------------------------------
    //! @brief      バッファを取得します.
    //!
    //! @return     バッファを返却します.
    //-------------------------------------------------------------------------
    ID3D11Buffer* const GetBuffer() const;

    //-------------------------------------------------------------------------
    //! @brief      シェーダリソースビューを取得します.
    //!
    //! @return     シェーダリソースビューを返却します.
    //-------------------------------------------------------------------------
    ID3D11ShaderResourceView* const GetSRV() const;

    //-------------------------------------------------------------------------
    //! @brief      アンオーダードアクセスビューを取得します.
    //!
    //! @return     アンオーダードアクセスビューを返却します.
    //-------------------------------------------------------------------------
    ID3D11UnorderedAccessView* const GetUAV() const;

    //-------------------------------------------------------------------------
    //! @brief      アロー演算子です.
    //-------------------------------------------------------------------------
    ID3D11Buffer* const operator -> () const;

private:
    //=========================================================================
    // private variables.
    //=========================================================================
    RefPtr<ID3D11Buffer>                m_Buffer;   //!< バッファです.
    RefPtr<ID3D11ShaderResourceView>    m_SRV;      //!< シェーダリソースビューです.
    RefPtr<ID3D11UnorderedAccessView>   m_UAV;      //!< アンオーダードアクセスビューです.

    //=========================================================================
    // private methods.
    //=========================================================================
    /* NOTHING */
};


///////////////////////////////////////////////////////////////////////////////
// RawBuffer class
///////////////////////////////////////////////////////////////////////////////
class RawBuffer
{
    //=========================================================================
    // list of friend classes and methods.
    //=========================================================================
    /* NOTHING */

public:
    //=========================================================================
    // public variables.
    //=========================================================================
    /* NOTHING */

    //=========================================================================
    // public methods.
    //=========================================================================

    //-------------------------------------------------------------------------
    //! @brief      コンストラクタです.
    //-------------------------------------------------------------------------
    RawBuffer();

    //-------------------------------------------------------------------------
    //! @brief      デストラクタです.
    //-------------------------------------------------------------------------
    ~RawBuffer();

    //-------------------------------------------------------------------------
    //! @brief      初期化処理を行います.
    //!
    //! @param[in]      pDevice         デバイスです.
    //! @param[in]      size            バッファサイズです.
    //! @param[in]      pInitData       初期化データです.
    //! @param[in]      uav             アンオーダードアクセスビューとして有効にする場合は true.
    //! @retval true    初期化に成功.
    //! @retval false   初期化に失敗.
    //-------------------------------------------------------------------------
    bool Init(ID3D11Device* pDevice, uint32_t size, const void* pInitData, bool uav = false);

    //-------------------------------------------------------------------------
    //! @brief      終了処理です.
    //-------------------------------------------------------------------------
    void Term();

    //-------------------------------------------------------------------------
    //! @brief      バッファを取得します.
    //!
    //! @return     バッファを返却します.
    //-------------------------------------------------------------------------
    ID3D11Buffer* const GetBuffer() const;

    //-------------------------------------------------------------------------
    //! @brief      シェーダリソースビューを取得します.
    //!
    //! @return     シェーダリソースビューを返却します.
    //-------------------------------------------------------------------------
    ID3D11ShaderResourceView* const GetSRV() const;

    //-------------------------------------------------------------------------
    //! @brief      アンオーダードアクセスビューを取得します.
    //!
    //! @return     アンオーダードアクセスビューを返却します.
    //-------------------------------------------------------------------------
    ID3D11UnorderedAccessView* const GetUAV() const;

    //-------------------------------------------------------------------------
    //! @brief      アロー演算子です.
    //-------------------------------------------------------------------------
    ID3D11Buffer* const operator -> () const;

private:
    //=========================================================================
    // private variables.
    //=========================================================================
    RefPtr<ID3D11Buffer>                m_Buffer;   //!< バッファです.
    RefPtr<ID3D11ShaderResourceView>    m_SRV;      //!< シェーダリソースビューです.
    RefPtr<ID3D11UnorderedAccessView>   m_UAV;      //!< アンオーダードアクセスビューです.

    //=========================================================================
    // private methods.
    //=========================================================================
    /* NOTHING */
};

} // namespace asdx
