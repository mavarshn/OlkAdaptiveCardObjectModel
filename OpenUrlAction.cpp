#include "stdafx.h"
#include "OpenUrlAction.h"
#include "ParseUtil.h"

using namespace AdaptiveCards;

OpenUrlAction::OpenUrlAction() : BaseActionElement(ActionType::OpenUrl)
{
}

std::shared_ptr<OpenUrlAction> OpenUrlAction::Deserialize(const Mso::Json::value& json)
{
    std::shared_ptr<OpenUrlAction> openUrlAction = BaseActionElement::Deserialize<OpenUrlAction>(json);

    openUrlAction->SetUrl(ParseUtil::GetString(json, AdaptiveCardSchemaKey::Url, true));

    return openUrlAction;
}

std::shared_ptr<OpenUrlAction> OpenUrlAction::DeserializeFromString(const std::wstring& jsonString)
{
    return OpenUrlAction::Deserialize(ParseUtil::GetJsonValueFromString(jsonString));
}

std::wstring OpenUrlAction::Serialize()
{
   
    return SerializeToJsonValue().to_string();
}

Mso::Json::value OpenUrlAction::SerializeToJsonValue()
{
    Mso::Json::value root = BaseActionElement::SerializeToJsonValue();

    root[AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::Url)] = Mso::Json::value(GetUrl());

    return root;
}

std::wstring OpenUrlAction::GetUrl() const
{
    return m_url;
}

void OpenUrlAction::SetUrl(const std::wstring value)
{
    m_url = value;
}


