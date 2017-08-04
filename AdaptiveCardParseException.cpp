#include "stdafx.h"
#include "AdaptiveCardParseException.h"
#include <locale>
#include <codecvt>

using namespace AdaptiveCards;

AdaptiveCardParseException::AdaptiveCardParseException(const std::wstring&  message) : m_message(message)
{
}

AdaptiveCardParseException::~AdaptiveCardParseException()
{
}

inline std::string ConvertWideStringToString(const std::wstring& wideString)
{
    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> convert;
    return convert.to_bytes(wideString);
}

const char * AdaptiveCardParseException::what() const throw()
{
    return ConvertWideStringToString(m_message).c_str();
}

