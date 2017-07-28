#pragma once

#include "stdafx.h"

namespace AdaptiveCards
{

class AdaptiveCardParseException : public std::exception
{
public:
    AdaptiveCardParseException(const std::wstring& message);
    ~AdaptiveCardParseException();

    virtual const char* what() const throw();

private:
    const std::wstring m_message;
};

}
