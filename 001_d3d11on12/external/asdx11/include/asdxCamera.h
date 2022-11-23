﻿//-----------------------------------------------------------------------------
// File : asdxCamera.h
// Desc : Camera Module.
// Copyright(c) Project Asura. All right reserved.
//-----------------------------------------------------------------------------
#pragma once

//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------
#include <asdxMath.h>


namespace asdx {

///////////////////////////////////////////////////////////////////////////////
// CameraEvent struct
///////////////////////////////////////////////////////////////////////////////
struct CameraEvent
{
    ///////////////////////////////////////////////////////////////////////////
    // EVENT_TYPE enum
    ///////////////////////////////////////////////////////////////////////////
    enum EVENT_TYPE
    {
        EVENT_ROTATE  = 0x000001 << 0,     //!< ターゲットを中心に回転.
        EVENT_DOLLY   = 0x000001 << 1,     //!< ドリー.
        EVENT_TRUCK   = 0x000001 << 2,     //!< 平行移動.
        EVENT_TWIST   = 0x000001 << 3,     //!< ツイスト.
        EVENT_PANTILT = 0x000001 << 4,     //!< パン・チルト.
        EVENT_RESET   = 0x000001 << 5,     //!< リセット.
    };

    asdx::Vector2   Rotate;     //!< 回転角です.
    asdx::Vector2   PanTilt;    //!< パン・チルト角.
    asdx::Vector3   Truck;      //!< トラック量です.
    float           Twist;      //!< ツイスト角です.
    float           Dolly;      //!< ドリー量です.
    uint32_t        Flags;      //!< フラグです.

    //-------------------------------------------------------------------------
    //! @brief      コンストラクタです.
    //-------------------------------------------------------------------------
    CameraEvent()
    : Rotate    ( 0.0f, 0.0f )
    , PanTilt   ( 0.0f, 0.0f )
    , Truck     ( 0.0f, 0.0f, 0.0f )
    , Twist     ( 0.0f )
    , Dolly     ( 0.0f )
    , Flags     ( 0 )
    { /* DO_NOTHING */ }
};


///////////////////////////////////////////////////////////////////////////////
// Camera class
///////////////////////////////////////////////////////////////////////////////
class Camera
{
    //=========================================================================
    // list of friend classes and methods.
    //=========================================================================
    /* NOTHING */

public:
    //=========================================================================
    // public variables
    //=========================================================================
    struct Param
    {
        asdx::Vector3 Position;      //!< カメラの位置です.
        asdx::Vector3 Target;        //!< カメラの注視点です.
        asdx::Vector3 Upward;        //!< カメラの上向きベクトルです.
        asdx::Vector2 Rotate;        //!< 回転角です.
        asdx::Vector2 PanTilt;       //!< パン・チルト角です.
        float         Twist;         //!< ツイスト角です.
        float         MinDist;       //!< ターゲットとの最小距離です.
        float         MaxDist;       //!< ターゲットとの最大距離です.

        //---------------------------------------------------------------------
        //! @brief      コンストラクタです.
        //---------------------------------------------------------------------
        Param()
        : Position  ( 0.0f, 0.0f, 5.0f )
        , Target    ( 0.0f, 0.0f, 0.0f )
        , Upward    ( 0.0f, 1.0f, 0.0f )
        , Rotate    ( 0.0f, 0.0f )
        , PanTilt   ( 0.0f, 0.0f )
        , Twist     ( 0.0f )
        , MinDist   ( 0.01f )
        , MaxDist   ( 1000.0f )
        { /* DO_NOTHING */ }
    };

    //=========================================================================
    // public methods.
    //=========================================================================

    //-------------------------------------------------------------------------
    //! @brief      コンストラクタです.
    //-------------------------------------------------------------------------
    Camera();

    //-------------------------------------------------------------------------
    //! @brief      デストラクタです.
    //-------------------------------------------------------------------------
    virtual ~Camera();

    //-------------------------------------------------------------------------
    //! @brief      カメラ位置を設定します.
    //!
    //! @param [in]     position        設定するカメラ位置です.
    //-------------------------------------------------------------------------
    void SetPosition( const asdx::Vector3& position );

    //-------------------------------------------------------------------------
    //! @brief      カメラ注視点を設定します.
    //!
    //! @param [in]     target          設定するカメラ注視点です.
    //-------------------------------------------------------------------------
    void SetTarget( const asdx::Vector3& target );

    //-------------------------------------------------------------------------
    //! @brief      カメラ上向きベクトルを設定します.
    //!
    //! @param [in]     upward          設定するカメラ上向きベクトルです.
    //-------------------------------------------------------------------------
    void SetUpward( const asdx::Vector3& upward );

    //-------------------------------------------------------------------------
    //! @brief      ツイスト角を設定します.
    //!
    //! @param [in]     twist           設定するツイスト角です.
    //-------------------------------------------------------------------------
    void SetTwist( const float twist );

    //-------------------------------------------------------------------------
    //! @brief      可動距離範囲を設定します.
    //!
    //! @param [in]     minDist         設定するカメラ注視点との最小距離.
    //! @param [in]     maxDist         設定するカメラ注視点との最大距離.
    //-------------------------------------------------------------------------
    void SetRange( const float minDist, const float maxDist );

    //-------------------------------------------------------------------------
    //! @brief      カメラパラメータを記憶します.
    //-------------------------------------------------------------------------
    void Preset();

    //-------------------------------------------------------------------------
    //! @brief      カメラパラメータをリセットします.
    //-------------------------------------------------------------------------
    void Reset();

    //-------------------------------------------------------------------------
    //! @brief      ビュー行列を更新します.
    //-------------------------------------------------------------------------
    void Update();

    //-------------------------------------------------------------------------
    //! @brief      カメライベントを基にビュー行列を更新します.
    //-------------------------------------------------------------------------
    void UpdateByEvent( const CameraEvent& camEvent );

    //-------------------------------------------------------------------------
    //! @brief      ビュー行列を取得します.
    //!
    //! @return     ビュー行列を返却します.
    //-------------------------------------------------------------------------
    const asdx::Matrix& GetView() const;

    //-------------------------------------------------------------------------
    //! @brief      カメラ位置を取得します.
    //!
    //! @return     カメラ位置を返却します.
    //-------------------------------------------------------------------------
    const asdx::Vector3& GetPosition() const;

    //-------------------------------------------------------------------------
    //! @brief      カメラ注視点を取得します.
    //!
    //! @return     カメラ注視点を返却します.
    //-------------------------------------------------------------------------
    const asdx::Vector3& GetTarget() const;

    //-------------------------------------------------------------------------
    //! @brief      カメラ上向きベクトルを取得します.
    //!
    //! @return     カメラ上向きベクトルを返却します.
    //-------------------------------------------------------------------------
    const asdx::Vector3& GetUpward() const;

    //-------------------------------------------------------------------------
    //! @brief      ツイスト角を取得します.
    //!
    //! @return     ツイスト角を返却します.
    //-------------------------------------------------------------------------
    float GetTwist() const;

    //-------------------------------------------------------------------------
    //! @brief      可動最小距離(カメラ注視点との最小距離)を取得します.
    //!
    //! @return     可動最小距離を返却します.
    //-------------------------------------------------------------------------
    float GetMinDist() const;

    //-------------------------------------------------------------------------
    //! @brief      可動最大距離(カメラ注視点との最大距離)を取得します.
    //!
    //! @return     可動最大距離を返却します.
    //-------------------------------------------------------------------------
    float GetMaxDist() const;

    //-------------------------------------------------------------------------
    //! @brief      カメラ基底ベクトルのX軸を取得します.
    //!
    //! @return     カメラ基底ベクトルのX軸を返却します.
    //-------------------------------------------------------------------------
    asdx::Vector3 GetAxisX() const;

    //-------------------------------------------------------------------------
    //! @brief      カメラ基底ベクトルのY軸を取得します.
    //!
    //! @return     カメラ基底ベクトルのY軸を返却します.
    //-------------------------------------------------------------------------
    asdx::Vector3 GetAxisY() const;

    //-------------------------------------------------------------------------
    //! @brief      カメラ基底ベクトルのZ軸を取得します.
    //!
    //! @return     カメラ基底ベクトルのZ軸を返却します.
    //-------------------------------------------------------------------------
    asdx::Vector3 GetAxisZ() const;

private:
    //=========================================================================
    // private variables
    //=========================================================================
    Param           m_Param;        //!< 計算用カメラパラメータです.
    Param           m_Preset;       //!< リセット用カメラパラメータです.
    asdx::Matrix    m_View;         //!< ビュー行列です.

    //=========================================================================
    // praviate methods.
    //=========================================================================

    //-------------------------------------------------------------------------
    //! @brief      角度を計算します.
    //-------------------------------------------------------------------------
    void ComputeAngle();

    //-------------------------------------------------------------------------
    //! @brief      位置座標を計算します.
    //-------------------------------------------------------------------------
    void ComputePosition();

    //-------------------------------------------------------------------------
    //! @brief      注視点を計算します.
    //-------------------------------------------------------------------------
    void ComputeTarget();

    //-------------------------------------------------------------------------
    //! @brief      可動距離範囲内に制限します.
    //-------------------------------------------------------------------------
    void ClampDist();
};


///////////////////////////////////////////////////////////////////////////////
// ViewerCamera class
///////////////////////////////////////////////////////////////////////////////
class ViewerCamera : public Camera
{
    //=========================================================================
    // list of friend classed and methods.
    //=========================================================================
    /* NOTHING */

public:
    ///////////////////////////////////////////////////////////////////////////
    // CONTROL_TYPE enum
    ///////////////////////////////////////////////////////////////////////////
    enum CONTROL_TYPE
    {
        CONTROL_TYPE_TARGET = 0,    //!< 注視点カメラ.
        CONTROL_TYPE_FREE           //!< フリーカメラ.
    };

    ///////////////////////////////////////////////////////////////////////////
    // Gain structure
    ///////////////////////////////////////////////////////////////////////////
    struct Gain
    {
        float       Dolly;            //!< ドリー調整係数です. 
        float       Rotate;           //!< 回転調整係数です.
        float       Move;             //!< 移動調整係数です.
        float       Wheel;            //!< ホイール調整係数です.
    };

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
    ViewerCamera();

    //-------------------------------------------------------------------------
    //! @brief      デストラクタです.
    //-------------------------------------------------------------------------
    virtual ~ViewerCamera();

    //-------------------------------------------------------------------------
    //! @brief      初期設定を行います.
    //-------------------------------------------------------------------------
    void Init(
        asdx::Vector3 cameraPos,
        asdx::Vector3 cameraAim,
        asdx::Vector3 cameraUp,
        float         fieldOfView,
        float         aspectRatio,
        float         nearClip,
        float         farClip
    );

    //-------------------------------------------------------------------------
    //! @brief      マウスの処理です.
    //-------------------------------------------------------------------------
    void OnMouse(
        int x,
        int y,
        int wheelDelta,
        bool isLeftButtonDown,
        bool isRightButtonDown,
        bool isMiddleButtonDown,
        bool isSideButton1Down,
        bool isSideButton2Down
    );

    //-------------------------------------------------------------------------
    //! @brief      キーの処理です.
    //-------------------------------------------------------------------------
    void OnKey( uint32_t nChar, bool isKeyDown, bool isAltDown );

    //-------------------------------------------------------------------------
    //! @brief      射影行列を取得します.
    //-------------------------------------------------------------------------
    const asdx::Matrix& GetProj() const;

    //-------------------------------------------------------------------------
    //! @brief      調整係数を取得します.
    //-------------------------------------------------------------------------
    const Gain& GetGain() const { return m_Gain[m_Type]; }

    //-------------------------------------------------------------------------
    //! @brief      カメラタイプを取得します.
    //-------------------------------------------------------------------------
    CONTROL_TYPE GetType() const { return m_Type; }

    //-------------------------------------------------------------------------
    //! @brief      ドリー調整係数を設定します.
    //-------------------------------------------------------------------------
    void SetDollyGain(float value) { m_Gain[m_Type].Dolly = value; }

    //-------------------------------------------------------------------------
    //! @brief      回転調整係数を設定します.
    //-------------------------------------------------------------------------
    void SetRotateGain(float value) { m_Gain[m_Type].Rotate = value; }

    //-------------------------------------------------------------------------
    //! @brief      移動調整係数を設定します.
    //-------------------------------------------------------------------------
    void SetMoveGain(float value) { m_Gain[m_Type].Move = value; }

    //-------------------------------------------------------------------------
    //! @brief      ホイール調整係数を設定します.
    //-------------------------------------------------------------------------
    void SetWheelGain(float value) { m_Gain[m_Type].Wheel = value; }

    //-------------------------------------------------------------------------
    //! @brief      カメラタイプを設定します.
    //-------------------------------------------------------------------------
    void SetType(CONTROL_TYPE value) { m_Type = value; }

    //-------------------------------------------------------------------------
    //! @brief      調整係数をリセットします.
    //-------------------------------------------------------------------------
    void ResetGain();

    //-------------------------------------------------------------------------
    //! @brief      垂直画角を設定します.
    //-------------------------------------------------------------------------
    void SetFieldOfView(float value);

    //-------------------------------------------------------------------------
    //! @brief      アスペクト比を設定ます.
    //-------------------------------------------------------------------------
    void SetAspectRatio(float value);

    //-------------------------------------------------------------------------
    //! @brief      垂直画角を取得します.
    //-------------------------------------------------------------------------
    float GetFieldOfView() const { return m_ProjParam.FieldOfView; }

    //-------------------------------------------------------------------------
    //! @brief      アスペクト比を取得します.
    //-------------------------------------------------------------------------
    float GetAspectRaio() const { return m_ProjParam.AspectRatio; }

protected:
    //=========================================================================
    // protected variables
    //=========================================================================
    struct MouseState
    {
        int  X;             //!< 現在のカーソルのX座標です.
        int  Y;             //!< 現在のカーソルのY座標です.
        int  prevX;         //!< 以前のカーソルのX座標です.
        int  prevY;         //!< 以前のカーソルのY座標です.
        bool isClick;       //!< 現在ボタンが押されたかどうか.
        bool isPrevClick;   //!< 以前ボタンが押されたかどうか

        //---------------------------------------------------------------------
        //! @brief      コンストラクタです.
        //---------------------------------------------------------------------
        MouseState()
        : X          ( 0 )
        , Y          ( 0 )
        , prevX      ( 0 )
        , prevY      ( 0 )
        , isClick    ( false )
        , isPrevClick( false )
        { /* DO_NOTHING */ }

        //---------------------------------------------------------------------
        //! @brief      デストラクタです.
        //---------------------------------------------------------------------
        virtual ~MouseState()
        { /* DO_NOTHING */ }

        //---------------------------------------------------------------------
        //! @brief      パラメータをリセットします.
        //---------------------------------------------------------------------
        void Reset()
        {
            X           = 0;
            Y           = 0;
            prevX       = 0;
            prevY       = 0;
            isClick     = false;
            isPrevClick = false;
        }

        //---------------------------------------------------------------------
        //! @brief      パラメータを更新します.
        //!
        //! @param [in]     x       カーソルのX座標.
        //! @param [in]     y       カーソルのY座標.
        //! @param [in]     isDown  ボタンが押されていればtrue.
        //---------------------------------------------------------------------
        void Update( int x, int y, bool isDown )
        {
            // 以前の状態を更新.
            prevX       = X;
            prevY       = Y;
            isPrevClick = isClick;

            // 現在の状態を更新.
            X           = x;
            Y           = y;
            isClick     = isDown;
        }
    };

    ///////////////////////////////////////////////////////////////////////////
    // ProjParam structure
    ///////////////////////////////////////////////////////////////////////////
    struct ProjParam
    {
        float   FieldOfView;        //!< 垂直画角.
        float   AspectRatio;        //!< アスペクト比.
    };

    MouseState      m_MouseLeft;            //!< マウスの左ボタンの状態です.
    MouseState      m_MouseRight;           //!< マウスの右ボタンの状態です.
    MouseState      m_MouseMiddle;          //!< マウスの右ボタンの状態です.
    Gain            m_Gain[2];              //!< 調整係数です.
    CONTROL_TYPE    m_Type;                 //!< カメラタイプです.
    Matrix          m_Proj;                 //!< 射影行列.
    ProjParam       m_ProjParam;            //!< 射影パラメータ.
    ProjParam       m_ProjPreset;           //!< プリセット射影パラメータ.

    //=========================================================================
    // protected methods.
    //=========================================================================

    //-------------------------------------------------------------------------
    //! @brief      マウスの状態からカメライベントを生成します.
    //-------------------------------------------------------------------------
    CameraEvent MakeEventFromMouse( int wheelDelta );

    //-------------------------------------------------------------------------
    //! @brief      キーの状態からカメライベントを作成します.
    //-------------------------------------------------------------------------
    CameraEvent MakeEventFromKey( uint32_t nChar, bool isKeyDown, bool isAltDown );

private:
    //=========================================================================
    // private variables.
    //=========================================================================
    /* NOTHING */

    //=========================================================================
    // private methods.
    //=========================================================================
    /* NOTHING */
};

} // namespace asdx

