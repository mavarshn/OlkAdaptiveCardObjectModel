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

std::shared_ptr<NumberInput> NumberInput::Deserialize(const Json::Value& json)
{
    ParseUtil::ExpectTypeString(json, CardElementType::NumberInput);

    std::shared_ptr<NumberInput> numberInput = BaseInputElement::Deserialize<NumberInput>(json);

    numberInput->SetPlaceholder(ParseUtil::GetString(json, AdaptiveCardSchemaKey::Placeholder));
    numberInput->SetValue(ParseUtil::GetInt(json, AdaptiveCardSchemaKey::Value, 0));
    numberInput->SetMax(ParseUtil::GetInt(json, AdaptiveCardSchemaKey::Max, INT_MAX));
    numberInput->SetMin(ParseUtil::GetInt(json, AdaptiveCardSchemaKey::Min, INT_MIN));

    return numberInput;
}

std::shared_ptr<NumberInput> NumberInput::DeserializeFromString(const std::string& jsonString)
{
    return NumberInput::Deserialize(ParseUtil::GetJsonValueFromString(jsonString));
}

std::string NumberInput::Serialize()
{
    Json::FastWriter writer;
    return writer.write(SerializeToJsonValue());
}

Json::Value NumberInput::SerializeToJsonValue()
{
    Json::Value root = BaseInputElement::SerializeToJsonValue();

    root[AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::Max)] = GetMax();
    root[AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::Min)] = GetMin();
    root[AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::Placeholder)] = GetPlaceholder();
    root[AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::Value)] = GetValue();

    return root;
}

std::string NumberInput::GetPlaceholder() const
{
    return m_placeholder;
}

void NumberInput::SetPlaceholder(const std::string value)
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