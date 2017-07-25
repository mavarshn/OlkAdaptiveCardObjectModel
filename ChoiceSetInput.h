#pragma once

#include "stdafx.h"
#include "BaseInputElement.h"
#include "ChoiceInput.h"
#include "Enums.h"

namespace AdaptiveCards
{
class BaseInputElement;
class ChoiceSetInput : public BaseInputElement
{
public:
    ChoiceSetInput();
    ChoiceSetInput(SeparationStyle separation, std::string speak);
    ChoiceSetInput(SeparationStyle separation, std::string speak, std::vector<std::shared_ptr<ChoiceInput>>& choices);

    virtual std::string Serialize();
    virtual Json::Value SerializeToJsonValue();

    bool GetIsMultiSelect() const;
    void SetIsMultiSelect(const bool isMultiSelect);

    ChoiceSetStyle GetChoiceSetStyle() const;
    void SetChoiceSetStyle(const ChoiceSetStyle choiceSetStyle);

    std::vector<std::shared_ptr<ChoiceInput>>& GetChoices();
    const std::vector<std::shared_ptr<ChoiceInput>>& GetChoices() const;

    static std::shared_ptr<ChoiceSetInput> Deserialize(const Json::Value& root);
    static std::shared_ptr<ChoiceSetInput> DeserializeFromString(const std::string& jsonString);

private:
    bool m_isMultiSelect;
    ChoiceSetStyle m_choiceSetStyle;

    std::vector<std::shared_ptr<ChoiceInput>> m_choices; 
};
}