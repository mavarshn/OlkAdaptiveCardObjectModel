#include "stdafx.h"
#include "Fact.h"
#include "ParseUtil.h"

using namespace AdaptiveCards;

Fact::Fact()
{
}

Fact::Fact(std::wstring title, std::wstring value, std::wstring speak) : 
    m_title(title), m_value(value), m_speak(speak)
{
}

std::shared_ptr<Fact> Fact::Deserialize(const Mso::Json::value& json)
{
    std::wstring title = ParseUtil::GetString(json, AdaptiveCardSchemaKey::Title, true);
    std::wstring value = ParseUtil::GetString(json, AdaptiveCardSchemaKey::Value, true);
    std::wstring speak = ParseUtil::GetString(json, AdaptiveCardSchemaKey::Speak);

    auto fact = std::make_shared<Fact>(title, value, speak);
    return fact;
}

std::shared_ptr<Fact> Fact::DeserializeFromString(const std::wstring& jsonString)
{
    return Fact::Deserialize(ParseUtil::GetJsonValueFromString(jsonString));
}

std::wstring Fact::Serialize()
{
    return SerializeToJsonValue().to_string();
}

Mso::Json::value Fact::SerializeToJsonValue()
{
    Mso::Json::value root;
    root[AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::Title)] = Mso::Json::value(GetTitle());
    root[AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::Speak)] = Mso::Json::value(GetSpeak());
    root[AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::Value)] = Mso::Json::value(GetValue());

    return root;
}

std::wstring Fact::GetTitle() const
{
    return m_title;
}

void Fact::SetTitle(const std::wstring& value)
{
    m_title = value;
}

std::wstring Fact::GetValue() const
{
    return m_value;
}

void Fact::SetValue(const std::wstring& value)
{
    m_value = value;
}

std::wstring Fact::GetSpeak() const
{
    return m_speak;
}

void Fact::SetSpeak(const std::wstring& value)
{
    m_speak = value;
}
