#pragma once

#include "stdafx.h"
#include "BaseInputElement.h"
#include "Enums.h"

namespace AdaptiveCards
{
class ToggleInput : public BaseInputElement
{
public:
    ToggleInput();

    static std::shared_ptr<ToggleInput> Deserialize(const Mso::Json::value& root);
    static std::shared_ptr<ToggleInput> DeserializeFromString(const std::wstring& jsonString);

    virtual std::wstring Serialize();
    Mso::Json::value SerializeToJsonValue();

    std::wstring GetTitle() const;
    void SetTitle(const std::wstring value);

    std::wstring GetValue() const;
    void SetValue(const std::wstring value);

    std::wstring GetValueOff() const;
    void SetValueOff(const std::wstring value);

    std::wstring GetValueOn() const;
    void SetValueOn(const std::wstring value);

private:
    std::wstring m_title;
    std::wstring m_value;
    std::wstring m_valueOff;
    std::wstring m_valueOn;
};
}