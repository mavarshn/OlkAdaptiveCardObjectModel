#pragma once

#include "stdafx.h"
#include "Enums.h"
#include "BaseCardElement.h"
#include "Column.h"

namespace AdaptiveCards
{
class ColumnSet : public BaseCardElement
{
public:
    ColumnSet();
    ColumnSet(std::vector<std::shared_ptr<Column>>& columns);

    virtual std::wstring Serialize();
    Mso::Json::value SerializeToJsonValue();

    std::vector<std::shared_ptr<Column>>& GetColumns();
    const std::vector<std::shared_ptr<Column>>& GetColumns() const;
    static std::shared_ptr<ColumnSet> Deserialize(const Mso::Json::value& root);
    static std::shared_ptr<ColumnSet> DeserializeFromString(const std::wstring& jsonString);

private:
    static const std::unordered_map<CardElementType, std::function<std::shared_ptr<Column>(const Mso::Json::value&)>, EnumHash> ColumnParser;
    std::vector<std::shared_ptr<Column>> m_columns;
};
}