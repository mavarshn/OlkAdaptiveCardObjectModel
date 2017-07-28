#pragma once

#include "stdafx.h"
#include "BaseInputElement.h"
#include "Enums.h"

namespace AdaptiveCards
{
class DateInput : public BaseInputElement
{
public:
    DateInput();

    static std::shared_ptr<DateInput> Deserialize(const Mso::Json::value& root);
    static std::shared_ptr<DateInput> DeserializeFromString(const std::wstring& jsonString);

    virtual std::wstring Serialize();
    virtual Mso::Json::value SerializeToJsonValue();

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