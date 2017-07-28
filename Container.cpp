#include "stdafx.h"
#include "ChoiceSetInput.h"
#include "ColumnSet.h"
#include "Container.h"
#include "FactSet.h"
#include "Image.h"
#include "ImageSet.h"
#include "DateInput.h"
#include "NumberInput.h"
#include "ParseUtil.h"
#include "TextBlock.h"
#include "TextInput.h"
#include "TimeInput.h"
#include "ToggleInput.h"

using namespace AdaptiveCards;

const std::unordered_map<CardElementType, std::function<std::shared_ptr<BaseCardElement>(const Mso::Json::value&)>, EnumHash> Container::CardElementParsers =
{
    { CardElementType::ChoiceSetInput, ChoiceSetInput::Deserialize },
    { CardElementType::Container, Container::Deserialize },
    { CardElementType::ColumnSet, ColumnSet::Deserialize },
    { CardElementType::FactSet, FactSet::Deserialize },
    { CardElementType::Image, AdaptiveCards::Image::Deserialize },
    { CardElementType::ImageSet, ImageSet::Deserialize },
    { CardElementType::TextBlock, TextBlock::Deserialize },
    { CardElementType::DateInput, DateInput::Deserialize },
    { CardElementType::NumberInput, NumberInput::Deserialize },
    { CardElementType::TextInput, TextInput::Deserialize },
    { CardElementType::TimeInput, TimeInput::Deserialize },
    { CardElementType::ToggleInput, ToggleInput::Deserialize },
};

Container::Container() : BaseCardElement(CardElementType::Container), m_style(ContainerStyle::Normal)
{
}

Container::Container(
    SeparationStyle separation,
    std::wstring speak,
    ContainerStyle style,
    std::vector<std::shared_ptr<BaseCardElement>>& items) :
    BaseCardElement(CardElementType::Container, separation, speak),
    m_style(style),
    m_items(items)
{
}

Container::Container(
    SeparationStyle separation,
    std::wstring speak,
    ContainerStyle style) :
    BaseCardElement(CardElementType::Container, separation, speak),
    m_style(style)
{
}

const std::vector<std::shared_ptr<BaseCardElement>>& Container::GetItems() const
{
    return m_items;
}

std::vector<std::shared_ptr<BaseCardElement>>& Container::GetItems()
{
    return m_items;
}

ContainerStyle Container::GetContainerStyle() const
{
    return m_style;
}

void Container::SetContainerStyle(const ContainerStyle value)
{
    m_style = value;
}

std::shared_ptr<BaseActionElement> Container::GetSelectAction() const
{
    return m_selectAction;
}

void Container::SetSelectAction(const std::shared_ptr<BaseActionElement> action)
{
    m_selectAction = action;
}

std::wstring Container::Serialize()
{
   
    return SerializeToJsonValue().to_string();
}

Mso::Json::value Container::SerializeToJsonValue()
{
    Mso::Json::value root = BaseCardElement::SerializeToJsonValue();

    root[AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::Style)] = Mso::Json::value(ContainerStyleToString(GetContainerStyle()));

    std::wstring itemsPropertyName = AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::Items);
    root[itemsPropertyName] = Mso::Json::value::array();
    int i = 0;
    for (auto & cardElement : GetItems())
    {
        root[itemsPropertyName][i++] = cardElement->SerializeToJsonValue();
    }

    root[AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::SelectAction)] = Mso::Json::value(BaseCardElement::SerializeSelectAction(GetSelectAction()));

    return root;
}

std::shared_ptr<Container> Container::Deserialize(const Mso::Json::value& value)
{
    ParseUtil::ExpectTypeString(value, CardElementType::Container);

    auto container = BaseCardElement::Deserialize<Container>(value);

    container->SetContainerStyle(
        ParseUtil::GetEnumValue<ContainerStyle>(value, AdaptiveCardSchemaKey::Style, ContainerStyle::Normal, ContainerStyleFromString));

    // Parse Items
    auto cardElements = ParseUtil::GetElementCollection<BaseCardElement>(value, AdaptiveCardSchemaKey::Items, Container::CardElementParsers, true);
    container->m_items = std::move(cardElements);

    container->SetSelectAction(BaseCardElement::DeserializeSelectAction(value, AdaptiveCardSchemaKey::SelectAction));

    return container;
}

std::shared_ptr<Container> Container::DeserializeFromString(const std::wstring& jsonString)
{
    return Container::Deserialize(ParseUtil::GetJsonValueFromString(jsonString));
}