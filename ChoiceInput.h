#pragma once

#include "stdafx.h"
#include "Enums.h"
#include <jsondom/ijsondom.h>
#include <jsondom/JsonCommon.h>

namespace AdaptiveCards
{
class ChoiceInput
{
public:
    ChoiceInput();

    std::wstring Serialize();
    Mso::Json::value SerializeToJsonValue();

    std::wstring GetTitle() const;
    void SetTitle(const std::wstring& value);

    std::wstring GetValue() const;
    void SetValue(const std::wstring& value);

    bool GetIsSelected() const;
    void SetIsSelected(const bool value);

    std::wstring GetSpeak() const;
    void SetSpeak(const std::wstring& value);

    static std::shared_ptr<ChoiceInput> Deserialize(const Mso::Json::value& root);
    static std::shared_ptr<ChoiceInput> DeserializeFromString(const std::wstring& jsonString);

private:
    std::wstring m_title;
    std::wstring m_value;
    std::wstring m_speak;
    bool m_isSelected;
};
}
