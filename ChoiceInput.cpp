#include "stdafx.h"
#include "ChoiceInput.h"
#include "ParseUtil.h"
#include "Enums.h"

using namespace AdaptiveCards;

ChoiceInput::ChoiceInput() :
    m_isSelected(false)
{
}

std::shared_ptr<ChoiceInput> ChoiceInput::Deserialize(const Mso::Json::value& json)
{
    auto choice = std::make_shared<ChoiceInput>();

    choice->SetTitle(ParseUtil::GetString(json, AdaptiveCardSchemaKey::Title, true));
    choice->SetValue(ParseUtil::GetString(json, AdaptiveCardSchemaKey::Value, true));
    choice->SetSpeak(ParseUtil::GetString(json, AdaptiveCardSchemaKey::Speak));
    choice->SetIsSelected(ParseUtil::GetBool(json, AdaptiveCardSchemaKey::IsSelected, false));

    return choice;
}

std::shared_ptr<ChoiceInput> ChoiceInput::DeserializeFromString(const std::wstring& jsonString)
{
    return ChoiceInput::Deserialize(ParseUtil::GetJsonValueFromString(jsonString));
}

std::wstring ChoiceInput::Serialize()
{
    return SerializeToJsonValue().to_string();
}

Mso::Json::value ChoiceInput::SerializeToJsonValue()
{
    Mso::Json::value root;

    root[AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::Title)] = Mso::Json::value(GetTitle());
    root[AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::Value)] = Mso::Json::value(GetValue());
    root[AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::Speak)] = Mso::Json::value(GetSpeak());
    root[AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::IsSelected)] = Mso::Json::value(GetIsSelected());

    return root;
}

std::wstring ChoiceInput::GetTitle() const
{
    return m_title;
}

void ChoiceInput::SetTitle(const std::wstring& title)
{
    m_title = title;
}

std::wstring ChoiceInput::GetValue() const
{
    return m_value;
}

void ChoiceInput::SetValue(const std::wstring& value)
{
    m_value = value;
}

bool AdaptiveCards::ChoiceInput::GetIsSelected() const
{
    return m_isSelected;
}

void AdaptiveCards::ChoiceInput::SetIsSelected(const bool isSelected)
{
    m_isSelected = isSelected;
}

std::wstring ChoiceInput::GetSpeak() const
{
    return m_speak;
}

void ChoiceInput::SetSpeak(const std::wstring& value)
{
    m_speak = value;
}
