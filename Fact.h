#pragma once

#include "stdafx.h"
#include "Enums.h"
#include <jsondom/ijsondom.h>
#include <jsondom/JsonCommon.h>

namespace AdaptiveCards
{
class Fact
{
public:
    Fact();
    Fact(std::wstring title, std::wstring value, std::wstring speak);

    std::wstring Serialize();
    Mso::Json::value SerializeToJsonValue();

    std::wstring GetTitle() const;
    void SetTitle(const std::wstring value);

    std::wstring GetValue() const;
    void SetValue(const std::wstring value);

    std::wstring GetSpeak() const;
    void SetSpeak(const std::wstring value);

    static std::shared_ptr<Fact> Deserialize(const Mso::Json::value& root);
    static std::shared_ptr<Fact> DeserializeFromString(const std::wstring& jsonString);

private:
    std::wstring m_title;
    std::wstring m_value;
    std::wstring m_speak;
};
}
