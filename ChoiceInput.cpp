#include "stdafx.h"
#include "ChoiceInput.h"
#include "ParseUtil.h"
#include "Enums.h"

using namespace AdaptiveCards;

ChoiceInput::ChoiceInput() :
    m_isSelected(false)
{
}

std::shared_ptr<ChoiceInput> ChoiceInput::Deserialize(const Json::Value& json)
{
    auto choice = std::make_shared<ChoiceInput>();

    choice->SetTitle(ParseUtil::GetString(json, AdaptiveCardSchemaKey::Title, true));
    choice->SetValue(ParseUtil::GetString(json, AdaptiveCardSchemaKey::Value, true));
    choice->SetSpeak(ParseUtil::GetString(json, AdaptiveCardSchemaKey::Speak));
    choice->SetIsSelected(ParseUtil::GetBool(json, AdaptiveCardSchemaKey::IsSelected, false));

    return choice;
}

std::shared_ptr<ChoiceInput> ChoiceInput::DeserializeFromString(const std::string& jsonString)
{
    return ChoiceInput::Deserialize(ParseUtil::GetJsonValueFromString(jsonString));
}

std::string ChoiceInput::Serialize()
{
    Json::FastWriter writer;
    return writer.write(SerializeToJsonValue());
}

Json::Value ChoiceInput::SerializeToJsonValue()
{
    Json::Value root;

    root[AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::Title)] = GetTitle();
    root[AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::Value)] = GetValue();
    root[AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::Speak)] = GetSpeak();
    root[AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::IsSelected)] = GetIsSelected();

    return root;
}

std::string ChoiceInput::GetTitle() const
{
    return m_title;
}

void ChoiceInput::SetTitle(const std::string title)
{
    m_title = title;
}

std::string ChoiceInput::GetValue() const
{
    return m_value;
}

void ChoiceInput::SetValue(const std::string value)
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

std::string ChoiceInput::GetSpeak() const
{
    return m_speak;
}

void ChoiceInput::SetSpeak(const std::string value)
{
    m_speak = value;
}
