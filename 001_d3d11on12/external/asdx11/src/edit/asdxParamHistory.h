﻿//-----------------------------------------------------------------------------
// File : asdxParamHistory.h
// Desc : Parameter History
// Copyright(c) Project Asura. All right reserved.
//-----------------------------------------------------------------------------
#pragma once

//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------
#include <edit/asdxHistory.h>


namespace asdx {

///////////////////////////////////////////////////////////////////////////////
// ParamHistory
///////////////////////////////////////////////////////////////////////////////
template<typename T>
class ParamHistory : public asdx::IHistory
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
    ParamHistory(T* target, const T& value)
    : m_pTarget (target)
    , m_Curr    (value)
    , m_Prev    (*target)
    { /* DO_NOTHING */ }

    ParamHistory(T* target, const T& nextValue, const T& prevValue)
    : m_pTarget (target)
    , m_Curr    (nextValue)
    , m_Prev    (prevValue)
    { /* DO_NOTHING */ }

    //-------------------------------------------------------------------------
    //! @brief      やり直します.
    //-------------------------------------------------------------------------
    void Redo() override
    { *m_pTarget = m_Curr; }

    //-------------------------------------------------------------------------
    //! @brief      元に戻します.
    //-------------------------------------------------------------------------
    void Undo() override
    { *m_pTarget = m_Prev; }

private:
    //=========================================================================
    // private variables.
    //=========================================================================
    T*      m_pTarget;  //!< 変更対象.
    T       m_Prev;     //!< 変更前の値.
    T       m_Curr;     //!< 変更後の値.

    //=========================================================================
    // private methods.
    //=========================================================================
    /* NOTHING */
};

} // namespace asdx