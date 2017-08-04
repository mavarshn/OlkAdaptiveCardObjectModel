#include "stdafx.h"
#include "ParseUtil.h"
#include "SubmitAction.h"

using namespace AdaptiveCards;

SubmitAction::SubmitAction() : BaseActionElement(ActionType::Submit)
{
}

std::wstring SubmitAction::GetDataJson() const
{
    return m_dataJson;
}

void SubmitAction::SetDataJson(const std::wstring& value)
{
    m_dataJson = value;
}

std::shared_ptr<SubmitAction> SubmitAction::Deserialize(const Mso::Json::value& json)
{
    std::shared_ptr<SubmitAction> submitAction = BaseActionElement::Deserialize<SubmitAction>(json);

    submitAction->SetDataJson(ParseUtil::GetJsonString(json, AdaptiveCardSchemaKey::Data));

    return submitAction;
}

std::shared_ptr<SubmitAction> SubmitAction::DeserializeFromString(const std::wstring& jsonString)
{
    return SubmitAction::Deserialize(ParseUtil::GetJsonValueFromString(jsonString));
}

std::wstring SubmitAction::Serialize()
{
   
    return SerializeToJsonValue().to_string();
}

Mso::Json::value SubmitAction::SerializeToJsonValue()
{
    Mso::Json::value root = BaseActionElement::SerializeToJsonValue();

    root[AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::Data)] = Mso::Json::value(GetDataJson());

    return root;
}



