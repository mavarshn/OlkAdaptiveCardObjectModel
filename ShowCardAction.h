#pragma once

#include "stdafx.h"
#include "SharedAdaptiveCard.h"
#include "BaseActionElement.h"
#include "Enums.h"

namespace AdaptiveCards
{
class ShowCardAction : public BaseActionElement
{
public:
    ShowCardAction();

    static std::shared_ptr<ShowCardAction> Deserialize(const Mso::Json::value& root);
    static std::shared_ptr<ShowCardAction> DeserializeFromString(const std::wstring& jsonString);

    virtual std::wstring Serialize();
    virtual Mso::Json::value SerializeToJsonValue();

    std::shared_ptr<AdaptiveCard> GetCard() const;
    void SetCard(const std::shared_ptr<AdaptiveCard>);

private:
    std::shared_ptr<AdaptiveCard> m_card;
};
}