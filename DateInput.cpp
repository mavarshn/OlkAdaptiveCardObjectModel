#include "stdafx.h"
#include "DateInput.h"
#include "ParseUtil.h"

using namespace AdaptiveCards;

DateInput::DateInput() :
    BaseInputElement(CardElementType::DateInput)
{
}

std::shared_ptr<DateInput> DateInput::Deserialize(const Mso::Json::value& json)
{
    ParseUtil::ExpectTypeString(json, CardElementType::DateInput);

    std::shared_ptr<DateInput> dateInput = BaseInputElement::Deserialize<DateInput>(json);

    dateInput->SetMax(ParseUtil::GetString(json, AdaptiveCardSchemaKey::Max));
    dateInput->SetMin(ParseUtil::GetString(json, AdaptiveCardSchemaKey::Min));
    dateInput->SetPlaceholder(ParseUtil::GetString(json, AdaptiveCardSchemaKey::Placeholder));
    dateInput->SetValue(ParseUtil::GetString(json, AdaptiveCardSchemaKey::Value));

    return dateInput;
}

std::shared_ptr<DateInput> DateInput::DeserializeFromString(const std::wstring& jsonString)
{
    return DateInput::Deserialize(ParseUtil::GetJsonValueFromString(jsonString));
}

std::wstring DateInput::Serialize()
{
    return SerializeToJsonValue().to_string();
}

Mso::Json::value DateInput::SerializeToJsonValue()
{
    Mso::Json::value root = BaseInputElement::SerializeToJsonValue();

    root[AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::Max)] = Mso::Json::value(GetMax());
    root[AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::Min)] = Mso::Json::value(GetMin());
    root[AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::Placeholder)] = Mso::Json::value(GetPlaceholder());
    root[AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::Value)] = Mso::Json::value(GetValue());

    return root;
}

std::wstring DateInput::GetMax() const
{
    return m_max;
}

void DateInput::SetMax(const std::wstring& value)
{
    m_max = value;
}

std::wstring DateInput::GetMin() const
{
    return m_min;
}

void DateInput::SetMin(const std::wstring& value)
{
    m_min = value;
}

std::wstring DateInput::GetPlaceholder() const
{
    return m_placeholder;
}

void DateInput::SetPlaceholder(const std::wstring& value)
{
    m_placeholder = value;
}

std::wstring DateInput::GetValue() const
{
    return m_value;
}

void DateInput::SetValue(const std::wstring& value)
{
    m_value = value;
}
