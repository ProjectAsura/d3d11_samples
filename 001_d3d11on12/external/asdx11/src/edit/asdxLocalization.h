﻿//-----------------------------------------------------------------------------
// File : asdxLocalization.h
// Desc : Localization Infomation.
// Copyright(c) Project Asura. All right reserved.
//-----------------------------------------------------------------------------
#pragma once

//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------
#include <cstdint>
#include <asdxStringView.h>


namespace asdx {

///////////////////////////////////////////////////////////////////////////////
// LANGUAGE_TYPE enum
///////////////////////////////////////////////////////////////////////////////
enum LANGUAGE_TYPE
{
    LANGUAGE_JP,        //!< 日本語.
    LANGUAGE_EN,        //!< 英語.

    LANGUAGE_MAX,
};

//-----------------------------------------------------------------------------
//! @brief      現在の言語タイプを設定します.
//-----------------------------------------------------------------------------
void SetCurrentLanguageType(LANGUAGE_TYPE type);

//-----------------------------------------------------------------------------
//! @brief      現在の言語タイプを取得します.
//-----------------------------------------------------------------------------
LANGUAGE_TYPE GetCurrentLanguageType();


///////////////////////////////////////////////////////////////////////////////
// Localization class
///////////////////////////////////////////////////////////////////////////////
class Localization
{
    //=========================================================================
    // list of friend classes
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
    //! @brief      コンストラクタ.
    //-------------------------------------------------------------------------
    Localization(const char* jp, const char* en)
    : m_Tag{jp, en}
    { /* DO_NOTHING */ }

    //-------------------------------------------------------------------------
    //! @brief      const char* へのキャスト.
    //-------------------------------------------------------------------------
    operator const char* () const
    {
        auto type = GetCurrentLanguageType();
        return m_Tag[type].c_str();
    }

    //-------------------------------------------------------------------------
    //! @brief      文字列取得.
    //-------------------------------------------------------------------------
    const char* c_str() const
    {
        auto type = GetCurrentLanguageType();
        return m_Tag[type].c_str();
    }

    //-------------------------------------------------------------------------
    //! @brief      文字数取得.
    //-------------------------------------------------------------------------
    size_t size() const
    {
        auto type = GetCurrentLanguageType();
        return m_Tag[type].size();
    }

    //-------------------------------------------------------------------------
    //! @brief      言語を指定して文字列を取得します.
    //-------------------------------------------------------------------------
    const char* Get(LANGUAGE_TYPE type) const
    { return m_Tag[type].c_str(); }

    //-------------------------------------------------------------------------
    //! @brief      言語を指定文字数を取得します.
    //-------------------------------------------------------------------------
    size_t Length(LANGUAGE_TYPE type) const
    { return m_Tag[type].size(); }

private:
    //=========================================================================
    // private variables.
    //=========================================================================
    asdx::string_view   m_Tag[LANGUAGE_MAX];

    //=========================================================================
    // private methods.
    //=========================================================================
    /* NOTHING */
};

} // namespace asdx
