#include "stdafx.h"
#include "HttpAction.h"
#include "ParseUtil.h"

using namespace AdaptiveCards;

HttpAction::HttpAction() : BaseActionElement(ActionType::Http)
{
}

std::shared_ptr<HttpAction> HttpAction::Deserialize(const Mso::Json::value& json)
{
    std::shared_ptr<HttpAction> httpAction = BaseActionElement::Deserialize<HttpAction>(json);

    httpAction->SetUrl(ParseUtil::GetString(json, AdaptiveCardSchemaKey::Url, true));
    httpAction->SetBody(ParseUtil::GetString(json, AdaptiveCardSchemaKey::Body));
    httpAction->SetMethod(ParseUtil::GetString(json, AdaptiveCardSchemaKey::Method, true));

    return httpAction;
}

std::shared_ptr<HttpAction> HttpAction::DeserializeFromString(const std::wstring& jsonString)
{
    Mso::Json::value jsonValue(jsonString);

    return HttpAction::Deserialize(jsonValue);
}

std::wstring HttpAction::Serialize()
{
   
    return SerializeToJsonValue().to_string();
}

Mso::Json::value HttpAction::SerializeToJsonValue()
{
    Mso::Json::value root = BaseActionElement::SerializeToJsonValue();

    root[AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::Url)] = Mso::Json::value(GetUrl());
    root[AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::Body)] = Mso::Json::value(GetBody());
    root[AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::Method)] = Mso::Json::value(GetMethod());

    return root;
}


std::wstring HttpAction::GetUrl() const
{
    return m_url;
}

void HttpAction::SetUrl(const std::wstring value)
{
    m_url = value;
}

std::wstring HttpAction::GetBody() const
{
    return m_body;
}

void HttpAction::SetBody(const std::wstring value)
{
    m_body = value;
}

std::wstring HttpAction::GetMethod() const
{
    return m_method;
}

void HttpAction::SetMethod(const std::wstring value)
{
    m_method = value;
}

