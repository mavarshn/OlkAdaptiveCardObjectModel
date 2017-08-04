#include "stdafx.h"
#include "ChoiceInput.h"
#include "ChoiceSetInput.h"
#include "ParseUtil.h"

using namespace AdaptiveCards;

ChoiceSetInput::ChoiceSetInput() : BaseInputElement(CardElementType::ChoiceSetInput)
{
}

ChoiceSetInput::ChoiceSetInput(
    SeparationStyle separation,
    const std::wstring& speak,
    std::vector<std::shared_ptr<ChoiceInput>>& choices) :
    BaseInputElement(CardElementType::ChoiceSetInput, separation, speak),
    m_choices(choices)
{
}

ChoiceSetInput::ChoiceSetInput(
    SeparationStyle separation,
    std::wstring speak) :
    BaseInputElement(CardElementType::ChoiceSetInput, separation, speak)
{
}

const std::vector<std::shared_ptr<ChoiceInput>>& ChoiceSetInput::GetChoices() const
{
    return m_choices;
}

std::vector<std::shared_ptr<ChoiceInput>>& ChoiceSetInput::GetChoices()
{
    return m_choices;
}

std::wstring ChoiceSetInput::Serialize()
{
    return SerializeToJsonValue().to_string();
}

Mso::Json::value ChoiceSetInput::SerializeToJsonValue()
{
    Mso::Json::value root = BaseInputElement::SerializeToJsonValue();

    root[AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::Style)] = Mso::Json::value(ChoiceSetStyleToString(GetChoiceSetStyle()));
    root[AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::IsMultiSelect)] = Mso::Json::value(GetIsMultiSelect());

    std::wstring propertyName = AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::Choices);
    
    Mso::Json::value::element_vector e;
    int i = 0;
    for (const auto& choice : GetChoices())
    {
        e.push_back(std::make_pair(Mso::Json::value(i++), choice->SerializeToJsonValue()));
    }

    root[propertyName] = Mso::Json::value::array(e);

    return root;
}

bool AdaptiveCards::ChoiceSetInput::GetIsMultiSelect() const
{
    return m_isMultiSelect;
}

void AdaptiveCards::ChoiceSetInput::SetIsMultiSelect(const bool isMultiSelect)
{
    m_isMultiSelect = isMultiSelect;
}

ChoiceSetStyle AdaptiveCards::ChoiceSetInput::GetChoiceSetStyle() const
{
    return m_choiceSetStyle;
}

void AdaptiveCards::ChoiceSetInput::SetChoiceSetStyle(const ChoiceSetStyle choiceSetStyle)
{
    m_choiceSetStyle = choiceSetStyle;
}

std::shared_ptr<ChoiceSetInput> ChoiceSetInput::Deserialize(const Mso::Json::value& json)
{
    ParseUtil::ExpectTypeString(json, CardElementType::ChoiceSetInput);

    auto choiceSet = BaseInputElement::Deserialize<ChoiceSetInput>(json);

    choiceSet->SetChoiceSetStyle(ParseUtil::GetEnumValue<ChoiceSetStyle>(json, AdaptiveCardSchemaKey::Style, ChoiceSetStyle::Compact, ChoiceSetStyleFromString));
    choiceSet->SetIsMultiSelect(ParseUtil::GetBool(json, AdaptiveCardSchemaKey::IsMultiSelect, false));

    // Parse Choices
    auto choicesArray = ParseUtil::GetArray(json, AdaptiveCardSchemaKey::Choices, true);
    std::vector<std::shared_ptr<ChoiceInput>> choices;

    // Deserialize every choice in the array
    for (auto & element : choicesArray)
    {
        auto choice = ChoiceInput::Deserialize(element.second);
        if (choice != nullptr)
        {
            choices.push_back(choice);
        }
    }

    choiceSet->m_choices = std::move(choices);
    return choiceSet;
}

std::shared_ptr<ChoiceSetInput> ChoiceSetInput::DeserializeFromString(const std::wstring& jsonString)
{
    return ChoiceSetInput::Deserialize(ParseUtil::GetJsonValueFromString(jsonString));
}