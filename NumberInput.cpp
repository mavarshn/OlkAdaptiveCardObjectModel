#include "stdafx.h"
#include "NumberInput.h"
#include "ParseUtil.h"

using namespace AdaptiveCards;

AdaptiveCards::NumberInput::NumberInput() :
    BaseInputElement(CardElementType::NumberInput),
	AdaptiveCards::NumberInput::m_min(INT_MIN),
	AdaptiveCards::NumberInput::m_max(INT_MAX)
{
}

std::shared_ptr<NumberInput> NumberInput::Deserialize(const Mso::Json::value& json)
{
    ParseUtil::ExpectTypeString(json, CardElementType::NumberInput);

    std::shared_ptr<NumberInput> numberInput = BaseInputElement::Deserialize<NumberInput>(json);

    numberInput->SetPlaceholder(ParseUtil::GetString(json, AdaptiveCardSchemaKey::Placeholder));
    numberInput->SetValue(ParseUtil::GetInt(json, AdaptiveCardSchemaKey::Value, 0));
    numberInput->SetMax(ParseUtil::GetInt(json, AdaptiveCardSchemaKey::Max, INT_MAX));
    numberInput->SetMin(ParseUtil::GetInt(json, AdaptiveCardSchemaKey::Min, INT_MIN));

    return numberInput;
}

std::shared_ptr<NumberInput> NumberInput::DeserializeFromString(const std::wstring& jsonString)
{
    return NumberInput::Deserialize(ParseUtil::GetJsonValueFromString(jsonString));
}

std::wstring NumberInput::Serialize()
{
   
    return SerializeToJsonValue().to_string();
}

Mso::Json::value NumberInput::SerializeToJsonValue()
{
    Mso::Json::value root = BaseInputElement::SerializeToJsonValue();

    root[AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::Max)] = Mso::Json::value(GetMax());
    root[AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::Min)] = Mso::Json::value(GetMin());
    root[AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::Placeholder)] = Mso::Json::value(GetPlaceholder());
    root[AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::Value)] = Mso::Json::value(GetValue());

    return root;
}

std::wstring NumberInput::GetPlaceholder() const
{
    return m_placeholder;
}

void NumberInput::SetPlaceholder(const std::wstring& value)
{
    m_placeholder = value;
}

int NumberInput::GetValue() const
{
    return m_value;
}

void NumberInput::SetValue(const int value)
{
    m_value = value;
}

int NumberInput::GetMax() const
{
    return m_max;
}

void NumberInput::SetMax(const int value)
{
    m_max = value;
}

int NumberInput::GetMin() const
{
    return m_min;
}

void NumberInput::SetMin(const int value)
{
    m_min = value;
}