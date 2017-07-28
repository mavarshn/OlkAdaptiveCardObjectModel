#pragma once

#include "Enums.h"
#include "stdafx.h"
#include "BaseActionElement.h"
#include "BaseCardElement.h"

namespace AdaptiveCards
{
class Container : public BaseCardElement
{
public:
    Container();
    Container(SeparationStyle separation, std::wstring speak, ContainerStyle style);
    Container(SeparationStyle separation, std::wstring speak, ContainerStyle style, std::vector<std::shared_ptr<BaseCardElement>>& items);

    virtual std::wstring Serialize();
    Mso::Json::value SerializeToJsonValue();

    std::vector<std::shared_ptr<BaseCardElement>>& GetItems();
    const std::vector<std::shared_ptr<BaseCardElement>>& GetItems() const;

    ContainerStyle GetContainerStyle() const;
    void SetContainerStyle(const ContainerStyle value);

    static std::shared_ptr<Container> Deserialize(const Mso::Json::value& root);
    static std::shared_ptr<Container> DeserializeFromString(const std::wstring& jsonString);

    std::shared_ptr<BaseActionElement> GetSelectAction() const;
    void SetSelectAction(const std::shared_ptr<BaseActionElement> action);

private:
    static const std::unordered_map<CardElementType, std::function<std::shared_ptr<BaseCardElement>(const Mso::Json::value&)>, EnumHash> CardElementParsers;

    ContainerStyle m_style;
    std::vector<std::shared_ptr<AdaptiveCards::BaseCardElement>> m_items;
    std::shared_ptr<BaseActionElement> m_selectAction;
};
}