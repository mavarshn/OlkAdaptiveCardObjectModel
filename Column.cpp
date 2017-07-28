#include "stdafx.h"
#include "ChoiceSetInput.h"
#include "Column.h"
#include "ColumnSet.h"
#include "Container.h"
#include "DateInput.h"
#include "FactSet.h"
#include "Image.h"
#include "ImageSet.h"
#include "NumberInput.h"
#include "ParseUtil.h"
#include "TextBlock.h"
#include "TextInput.h"
#include "TimeInput.h"
#include "ToggleInput.h"

using namespace AdaptiveCards;

const std::unordered_map<CardElementType, std::function<std::shared_ptr<BaseCardElement>(const Mso::Json::value&)>, EnumHash> Column::CardElementParsers =
{
    { CardElementType::Container, Container::Deserialize },
    { CardElementType::ColumnSet, ColumnSet::Deserialize },
    { CardElementType::FactSet, FactSet::Deserialize },
    { CardElementType::Image, AdaptiveCards::Image::Deserialize },
    { CardElementType::ImageSet, ImageSet::Deserialize },
    { CardElementType::TextBlock, TextBlock::Deserialize },
    { CardElementType::ChoiceSetInput, ChoiceSetInput::Deserialize },
    { CardElementType::DateInput, DateInput::Deserialize },
    { CardElementType::NumberInput, NumberInput::Deserialize },
    { CardElementType::TextInput, TextInput::Deserialize },
    { CardElementType::TimeInput, TimeInput::Deserialize },
    { CardElementType::ToggleInput, ToggleInput::Deserialize },
};

Column::Column() : BaseCardElement(CardElementType::Column), m_size(L"Auto")
{
}

Column::Column(
    SeparationStyle separation,
    std::wstring speak,
    std::wstring size,
    std::vector<std::shared_ptr<BaseCardElement>>& items) :
    BaseCardElement(CardElementType::Column, separation, speak), m_size(size), m_items(items)
{
}

Column::Column(
    SeparationStyle separation,
    std::wstring speak,
    std::wstring size) :
    BaseCardElement(CardElementType::Column, separation, speak), m_size(size)
{
}

std::wstring Column::GetSize() const
{
    return m_size;
}

void Column::SetSize(const std::wstring value)
{
    m_size = value;
}

const std::vector<std::shared_ptr<BaseCardElement>>& Column::GetItems() const
{
    return m_items;
}

std::vector<std::shared_ptr<BaseCardElement>>& Column::GetItems()
{
    return m_items;
}

std::wstring Column::Serialize()
{
   
    return SerializeToJsonValue().to_string();
}

Mso::Json::value Column::SerializeToJsonValue()
{
    Mso::Json::value root = BaseCardElement::SerializeToJsonValue();

    root[AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::Size)] = Mso::Json::value(GetSize());

    std::wstring propertyName = AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::Items);
    root[propertyName] = Mso::Json::value::array();
    int i = 0;
    for (const auto& cardElement : GetItems())
    {
        root[propertyName][i++] = cardElement->SerializeToJsonValue();
    }

    root[AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::SelectAction)] = Mso::Json::value(BaseCardElement::SerializeSelectAction(GetSelectAction()));

    return root;
}

std::shared_ptr<Column> Column::Deserialize(const Mso::Json::value& value)
{
    ParseUtil::ExpectTypeString(value, CardElementType::Column);

    auto column = BaseCardElement::Deserialize<Column>(value);

    column->SetSize(ParseUtil::GetValueAsString(value, AdaptiveCardSchemaKey::Size));

    // Parse Items
    auto cardElements = ParseUtil::GetElementCollection<BaseCardElement>(value, AdaptiveCardSchemaKey::Items, CardElementParsers, true);
    column->m_items = std::move(cardElements);

    column->SetSelectAction(BaseCardElement::DeserializeSelectAction(value, AdaptiveCardSchemaKey::SelectAction));

    return column;
}

std::shared_ptr<Column> Column::DeserializeFromString(const std::wstring& jsonString)
{
    return Column::Deserialize(ParseUtil::GetJsonValueFromString(jsonString));
}

std::shared_ptr<BaseActionElement> Column::GetSelectAction() const
{
    return m_selectAction;
}

void Column::SetSelectAction(const std::shared_ptr<BaseActionElement> action)
{
    m_selectAction = action;
}