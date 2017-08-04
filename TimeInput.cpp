#include "stdafx.h"
#include "ParseUtil.h"
#include "TimeInput.h"

using namespace AdaptiveCards;

TimeInput::TimeInput() :
    BaseInputElement(CardElementType::TimeInput)
{
}

std::shared_ptr<TimeInput> TimeInput::Deserialize(const Mso::Json::value& json)
{
    ParseUtil::ExpectTypeString(json, CardElementType::TimeInput);

    std::shared_ptr<TimeInput> timeInput = BaseInputElement::Deserialize<TimeInput>(json);

    timeInput->SetMax(ParseUtil::GetString(json, AdaptiveCardSchemaKey::Max));
    timeInput->SetMin(ParseUtil::GetString(json, AdaptiveCardSchemaKey::Min));
    timeInput->SetPlaceholder(ParseUtil::GetString(json, AdaptiveCardSchemaKey::Placeholder));
    timeInput->SetValue(ParseUtil::GetString(json, AdaptiveCardSchemaKey::Value));

    return timeInput;
}

std::shared_ptr<TimeInput> TimeInput::DeserializeFromString(const std::wstring& jsonString)
{
    return TimeInput::Deserialize(ParseUtil::GetJsonValueFromString(jsonString));
}

std::wstring TimeInput::Serialize()
{
   
    return SerializeToJsonValue().to_string();
}

Mso::Json::value TimeInput::SerializeToJsonValue()
{
    Mso::Json::value root = BaseInputElement::SerializeToJsonValue();

    root[AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::Max)] = Mso::Json::value(GetMax());
    root[AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::Min)] = Mso::Json::value(GetMin());
    root[AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::Placeholder)] = Mso::Json::value(GetPlaceholder());
    root[AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::Value)] = Mso::Json::value(GetValue());

    return root;
}

std::wstring TimeInput::GetMax() const
{
    return m_max;
}

void TimeInput::SetMax(const std::wstring& value)
{
    m_max = value;
}

std::wstring TimeInput::GetMin() const
{
    return m_min;
}

void TimeInput::SetMin(const std::wstring& value)
{
    m_min = value;
}

std::wstring TimeInput::GetPlaceholder() const
{
    return m_placeholder;
}

void TimeInput::SetPlaceholder(const std::wstring& value)
{
    m_placeholder = value;
}

std::wstring TimeInput::GetValue() const
{
    return m_value;
}

void TimeInput::SetValue(const std::wstring& value)
{
    m_value = value;
}
