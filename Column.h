#pragma once

#include "stdafx.h"
#include "Enums.h"
#include "BaseActionElement.h"
#include "BaseCardElement.h"

namespace AdaptiveCards
{
class Column : public BaseCardElement
{
public:
    Column();
    Column(SeparationStyle separation, const std::wstring& speak, std::wstring size);
    Column(SeparationStyle separation, const std::wstring& speak, std::wstring size, std::vector<std::shared_ptr<BaseCardElement>>& items);

    virtual std::wstring Serialize();
    virtual Mso::Json::value SerializeToJsonValue();

    static std::shared_ptr<Column> Deserialize(const Mso::Json::value& root);
    static std::shared_ptr<Column> DeserializeFromString(const std::wstring& jsonString);

    std::wstring GetSize() const;
    void SetSize(const std::wstring& value);

    std::vector<std::shared_ptr<BaseCardElement>>& GetItems();
    const std::vector<std::shared_ptr<BaseCardElement>>& GetItems() const;

    std::shared_ptr<BaseActionElement> GetSelectAction() const;
    void SetSelectAction(const std::shared_ptr<BaseActionElement> action);

private:
    static const std::unordered_map<CardElementType, std::function<std::shared_ptr<BaseCardElement>(const Mso::Json::value&)>, EnumHash> CardElementParsers;
    std::wstring m_size;
    std::vector<std::shared_ptr<AdaptiveCards::BaseCardElement>> m_items;
    std::shared_ptr<BaseActionElement> m_selectAction;
};
}