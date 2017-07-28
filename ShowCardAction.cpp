#include "stdafx.h"
#include "SharedAdaptiveCard.h"
#include "ParseUtil.h"
#include "ShowCardAction.h"

using namespace AdaptiveCards;

ShowCardAction::ShowCardAction() : BaseActionElement(ActionType::ShowCard)
{
}

std::shared_ptr<ShowCardAction> ShowCardAction::Deserialize(const Mso::Json::value& json)
{
    std::shared_ptr<ShowCardAction> showCardAction = BaseActionElement::Deserialize<ShowCardAction>(json);

    std::wstring propertyName = AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::Card);
    showCardAction->SetCard(AdaptiveCard::Deserialize(ParseUtil::GetValue(json, propertyName)));

    return showCardAction;
}

std::shared_ptr<ShowCardAction> ShowCardAction::DeserializeFromString(const std::wstring& jsonString)
{
    return ShowCardAction::Deserialize(ParseUtil::GetJsonValueFromString(jsonString));
}

std::wstring ShowCardAction::Serialize()
{
   
    return SerializeToJsonValue().to_string();
}

Mso::Json::value ShowCardAction::SerializeToJsonValue()
{
    Mso::Json::value root = BaseActionElement::SerializeToJsonValue();

    root[AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::Card)] = Mso::Json::value(GetCard()->SerializeToJsonValue());

    return root;
}

std::shared_ptr<AdaptiveCard> AdaptiveCards::ShowCardAction::GetCard() const
{
    return m_card;
}

void AdaptiveCards::ShowCardAction::SetCard(const std::shared_ptr<AdaptiveCard> card)
{
    m_card = card;
}
