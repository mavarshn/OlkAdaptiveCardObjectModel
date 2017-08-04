#pragma once

#include "stdafx.h"
#include "BaseInputElement.h"
#include "Enums.h"

namespace AdaptiveCards
{
class NumberInput : public BaseInputElement
{
public:
    NumberInput();

    static std::shared_ptr<NumberInput> Deserialize(const Mso::Json::value& root);
    static std::shared_ptr<NumberInput> DeserializeFromString(const std::wstring& jsonString);

    virtual std::wstring Serialize();
    virtual Mso::Json::value SerializeToJsonValue();

    std::wstring GetPlaceholder() const;
    void SetPlaceholder(const std::wstring& value);

    int GetValue() const;
    void SetValue(const int value);

    int GetMax() const;
    void SetMax(const int value);

    int GetMin() const;
    void SetMin(const int value);

private:
    std::wstring m_placeholder;
    int m_value;
    int m_max;
    int m_min;
};
}