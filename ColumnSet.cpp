#include "stdafx.h"
#include "ColumnSet.h"
#include "ParseUtil.h"
#include "Image.h"
#include "TextBlock.h"

using namespace AdaptiveCards;

const std::unordered_map<CardElementType, std::function<std::shared_ptr<Column>(const Mso::Json::value&)>, EnumHash> ColumnSet::ColumnParser =
{
    { CardElementType::Column, Column::Deserialize }
};

ColumnSet::ColumnSet() : BaseCardElement(CardElementType::ColumnSet)
{
}

ColumnSet::ColumnSet(std::vector<std::shared_ptr<Column>>& columns) : BaseCardElement(CardElementType::ColumnSet), m_columns(columns)
{
}

const std::vector<std::shared_ptr<Column>>& ColumnSet::GetColumns() const
{
    return m_columns;
}

std::vector<std::shared_ptr<Column>>& ColumnSet::GetColumns()
{
    return m_columns;
}

std::wstring ColumnSet::Serialize()
{
   
    return SerializeToJsonValue().to_string();
}

Mso::Json::value ColumnSet::SerializeToJsonValue()
{
    Mso::Json::value root = BaseCardElement::SerializeToJsonValue();

    std::wstring propertyName = AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::Columns);

    root[propertyName] = Mso::Json::value::array();
    
    int i = 0;
    for (const auto& column : GetColumns())
    {
        root[propertyName][i++] = column->SerializeToJsonValue();
    }
    return root;
}

std::shared_ptr<ColumnSet> ColumnSet::Deserialize(const Mso::Json::value& value)
{
    ParseUtil::ExpectTypeString(value, CardElementType::ColumnSet);

    auto container = BaseCardElement::Deserialize<ColumnSet>(value);

    // Parse Columns
    auto cardElements = ParseUtil::GetElementCollection<Column>(value, AdaptiveCardSchemaKey::Columns, ColumnParser, true);
    container->m_columns = std::move(cardElements);
    return container;
}

std::shared_ptr<ColumnSet> ColumnSet::DeserializeFromString(const std::wstring& jsonString)
{
    return ColumnSet::Deserialize(ParseUtil::GetJsonValueFromString(jsonString));
}