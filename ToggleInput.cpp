#include "stdafx.h"
#include "ToggleInput.h"
#include "ParseUtil.h"

using namespace AdaptiveCards;

ToggleInput::ToggleInput() :
    BaseInputElement(CardElementType::ToggleInput),
    m_valueOn(L"true"),
    m_valueOff(L"false")
{
}

std::shared_ptr<ToggleInput> ToggleInput::Deserialize(const Mso::Json::value& json)
{
    ParseUtil::ExpectTypeString(json, CardElementType::ToggleInput);

    std::shared_ptr<ToggleInput> toggleInput = BaseInputElement::Deserialize<ToggleInput>(json);

    toggleInput->SetTitle(ParseUtil::GetString(json, AdaptiveCardSchemaKey::Title, true));
    toggleInput->SetValue(ParseUtil::GetString(json, AdaptiveCardSchemaKey::Value));

    std::wstring valueOff = ParseUtil::GetString(json, AdaptiveCardSchemaKey::ValueOff);
    if (valueOff != L"")
    {
        toggleInput->SetValueOff(valueOff);
    }

    std::wstring valueOn = ParseUtil::GetString(json, AdaptiveCardSchemaKey::ValueOn);
    if (valueOn != L"")
    {
        toggleInput->SetValueOn(valueOn);
    }

    return toggleInput;
}

std::shared_ptr<ToggleInput> ToggleInput::DeserializeFromString(const std::wstring& jsonString)
{
    return ToggleInput::Deserialize(ParseUtil::GetJsonValueFromString(jsonString));
}

std::wstring ToggleInput::Serialize()
{
   
    return SerializeToJsonValue().to_string();
}

Mso::Json::value ToggleInput::SerializeToJsonValue()
{
    Mso::Json::value root = BaseInputElement::SerializeToJsonValue();

    root[AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::Title)] = Mso::Json::value(GetTitle());
    root[AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::Value)] = Mso::Json::value(GetValue());
    root[AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::ValueOff)] = Mso::Json::value(GetValueOff());
    root[AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::ValueOn)] = Mso::Json::value(GetValueOn());

    return root;
}

std::wstring ToggleInput::GetTitle() const
{
    return m_title;
}

void ToggleInput::SetTitle(const std::wstring value)
{
    m_title = value;
}

std::wstring ToggleInput::GetValue() const
{
    return m_value;
}

void ToggleInput::SetValue(const std::wstring value)
{
    m_value = value;
}
void ToggleInput::SetValueOff(const std::wstring valueOff)
{
    m_valueOff = valueOff;
}

std::wstring ToggleInput::GetValueOff() const
{
    return m_valueOff;
}

std::wstring ToggleInput::GetValueOn() const
{
    return m_valueOn;
}

void ToggleInput::SetValueOn(const std::wstring valueOn)
{
    m_valueOn = valueOn;
}