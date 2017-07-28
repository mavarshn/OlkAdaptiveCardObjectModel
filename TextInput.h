#pragma once

#include "stdafx.h"
#include "BaseInputElement.h"
#include "Enums.h"

namespace AdaptiveCards
{
class TextInput : public BaseInputElement
{
public:
    TextInput();

    static std::shared_ptr<TextInput> Deserialize(const Mso::Json::value& root);
    static std::shared_ptr<TextInput> DeserializeFromString(const std::wstring& jsonString);

    virtual std::wstring Serialize();
    Mso::Json::value SerializeToJsonValue();

    std::wstring GetPlaceholder() const;
    void SetPlaceholder(const std::wstring value);

    std::wstring GetValue() const;
    void SetValue(const std::wstring value);

    bool GetIsMultiline() const;
    void SetIsMultiline(const bool value);

    unsigned int GetMaxLength() const;
    void SetMaxLength(const unsigned int value);

    TextInputStyle GetTextInputStyle() const;
    void SetTextInputStyle(const TextInputStyle value);

private:
    std::wstring m_placeholder;
    std::wstring m_value;
    bool m_isMultiline;
    unsigned int m_maxLength;
    TextInputStyle m_style;
};
}