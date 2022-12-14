//-----------------------------------------------------------------------------
// File : asdxStopWatch.h
// Desc : Stop Watch.
// Copyright(c) Project Asura. All right reserved.
//-----------------------------------------------------------------------------
#pragma once

//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------
#include <cstdint>
#include <profileapi.h>


namespace asdx {

///////////////////////////////////////////////////////////////////////////////
// StopWatch class
///////////////////////////////////////////////////////////////////////////////
class StopWatch
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
    StopWatch()
    : m_Start   ()
    , m_End     ()
    {
        LARGE_INTEGER freq;
        QueryPerformanceFrequency(&freq);
        m_InvTicksPerSec = 1.0 / double(freq.QuadPart);
    }

    //-------------------------------------------------------------------------
    //! @brief      開始点を記録します.
    //-------------------------------------------------------------------------
    void Start()
    { QueryPerformanceCounter(&m_Start); }

    //-------------------------------------------------------------------------
    //! @brief      終了点を記録します.
    //-------------------------------------------------------------------------
    void End()
    { QueryPerformanceCounter(&m_End); }

    //-------------------------------------------------------------------------
    //! @brief      経過時間を秒単位で取得します.
    //-------------------------------------------------------------------------
    double GetElapsedSec() const
    { return (m_End.QuadPart - m_Start.QuadPart) * m_InvTicksPerSec; }

    //-------------------------------------------------------------------------
    //! @brief      経過時間をミリ秒単位で取得します.
    //-------------------------------------------------------------------------
    double GetElapsedMsec() const 
    { return GetElapsedSec() * 1000.0f; }

private:
    //=========================================================================
    // private variables.
    //=========================================================================
    LARGE_INTEGER   m_Start;
    LARGE_INTEGER   m_End;
    double          m_InvTicksPerSec;

    //=========================================================================
    // private methods.
    //=========================================================================
    /* NOTHING */
};


} // namespace asdx
