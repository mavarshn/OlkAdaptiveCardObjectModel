#pragma once

#include "stdafx.h"
#include "Enums.h"
#include "json/json.h"

namespace AdaptiveCards
{
class ChoiceInput
{
public:
    ChoiceInput();

    std::string Serialize();
    Json::Value SerializeToJsonValue();

    std::string GetTitle() const;
    void SetTitle(const std::string value);

    std::string GetValue() const;
    void SetValue(const std::string value);

    bool GetIsSelected() const;
    void SetIsSelected(const bool value);

    std::string GetSpeak() const;
    void SetSpeak(const std::string value);

    static std::shared_ptr<ChoiceInput> Deserialize(const Json::Value& root);
    static std::shared_ptr<ChoiceInput> DeserializeFromString(const std::string& jsonString);

private:
    std::string m_title;
    std::string m_value;
    std::string m_speak;
    bool m_isSelected;
};
}
