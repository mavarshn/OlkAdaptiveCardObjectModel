#pragma once

#include "stdafx.h"
#include "BaseInputElement.h"
#include "Enums.h"

namespace AdaptiveCards
{
class TimeInput : public BaseInputElement
{
public:
    TimeInput();

    static std::shared_ptr<TimeInput> Deserialize(const Mso::Json::value& root);
    static std::shared_ptr<TimeInput> DeserializeFromString(const std::wstring& jsonString);

    virtual std::wstring Serialize();
    Mso::Json::value SerializeToJsonValue();

    std::wstring GetMax() const;
    void SetMax(const std::wstring value);

    std::wstring GetMin() const;
    void SetMin(const std::wstring value);

    std::wstring GetPlaceholder() const;
    void SetPlaceholder(const std::wstring value);

    std::wstring GetValue() const;
    void SetValue(const std::wstring value);

private:
    std::wstring m_max;
    std::wstring m_min;
    std::wstring m_placeholder;
    std::wstring m_value;
};
}