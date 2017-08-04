#include "stdafx.h"
#include "Image.h"
#include "ParseUtil.h"

using namespace AdaptiveCards;

AdaptiveCards::Image::Image() :
	BaseCardElement(AdaptiveCards::CardElementType::Image),
    m_imageStyle(AdaptiveCards::ImageStyle::Normal),
    m_imageSize(AdaptiveCards::ImageSize::Auto),
    m_hAlignment(AdaptiveCards::HorizontalAlignment::Left)
{
}

AdaptiveCards::Image::Image(AdaptiveCards::SeparationStyle separationStyle,
    const std::wstring& speak,
    std::wstring url,
	AdaptiveCards::ImageStyle imageStyle,
	AdaptiveCards::ImageSize imageSize,
    std::wstring altText,
	AdaptiveCards::HorizontalAlignment hAlignment) :
    BaseCardElement(CardElementType::Image, separationStyle, speak),
    m_url(url),
    m_imageStyle(imageStyle),
    m_imageSize(imageSize),
    m_altText(altText),
    m_hAlignment(hAlignment)
{
}

std::shared_ptr<AdaptiveCards::Image> AdaptiveCards::Image::Deserialize(const Mso::Json::value& json)
{
    ParseUtil::ExpectTypeString(json, AdaptiveCards::CardElementType::Image);

    std::shared_ptr<Image> image = BaseCardElement::Deserialize<Image>(json);

    image->SetUrl(ParseUtil::GetString(json, AdaptiveCardSchemaKey::Url, true));
    image->SetImageStyle(ParseUtil::GetEnumValue<ImageStyle>(json, AdaptiveCardSchemaKey::Style, ImageStyle::Normal, ImageStyleFromString));
    image->SetImageSize(ParseUtil::GetEnumValue<ImageSize>(json, AdaptiveCardSchemaKey::Size, ImageSize::Default, ImageSizeFromString));
    image->SetAltText(ParseUtil::GetString(json, AdaptiveCardSchemaKey::AltText));
    image->SetHorizontalAlignment(ParseUtil::GetEnumValue<HorizontalAlignment>(json, AdaptiveCardSchemaKey::HorizontalAlignment, HorizontalAlignment::Left, HorizontalAlignmentFromString));
    image->SetSelectAction(BaseCardElement::DeserializeSelectAction(json, AdaptiveCardSchemaKey::SelectAction));

    return image;
}

std::wstring AdaptiveCards::Image::Serialize()
{
   
    return SerializeToJsonValue().to_string();
}

Mso::Json::value AdaptiveCards::Image::SerializeToJsonValue()
{
    Mso::Json::value root = BaseCardElement::SerializeToJsonValue();

    root[AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::Size)] = Mso::Json::value(ImageSizeToString(GetImageSize()));
    root[AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::Style)] = Mso::Json::value(ImageStyleToString(GetImageStyle()));
    root[AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::Url)] = Mso::Json::value(GetUrl());
    root[AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::HorizontalAlignment)] =
        Mso::Json::value(HorizontalAlignmentToString(GetHorizontalAlignment()));
    root[AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::AltText)] = Mso::Json::value(GetAltText());

    root[AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::SelectAction)] = Mso::Json::value(BaseCardElement::SerializeSelectAction(GetSelectAction()));

    return root;
}

std::wstring AdaptiveCards::Image::GetUrl() const
{
    return m_url;
}

void AdaptiveCards::Image::SetUrl(const std::wstring& value)
{
    m_url = value;
}

ImageStyle AdaptiveCards::Image::GetImageStyle() const
{
    return m_imageStyle;
}

void AdaptiveCards::Image::SetImageStyle(const ImageStyle value)
{
    m_imageStyle = value;
}

ImageSize AdaptiveCards::Image::GetImageSize() const
{
    return m_imageSize;
}

void AdaptiveCards::Image::SetImageSize(const ImageSize value)
{
    m_imageSize = value;
}

std::wstring AdaptiveCards::Image::GetAltText() const
{
    return m_altText;
}

void AdaptiveCards::Image::SetAltText(const std::wstring& value)
{
    m_altText = value;
}

HorizontalAlignment AdaptiveCards::Image::GetHorizontalAlignment() const
{
    return m_hAlignment;
}

void AdaptiveCards::Image::SetHorizontalAlignment(const HorizontalAlignment value)
{
    m_hAlignment = value;
}

std::shared_ptr<AdaptiveCards::Image> AdaptiveCards::Image::DeserializeFromString(const std::wstring& jsonString)
{
    return AdaptiveCards::Image::Deserialize(ParseUtil::GetJsonValueFromString(jsonString));
}

std::shared_ptr<BaseActionElement> AdaptiveCards::Image::GetSelectAction() const
{
    return m_selectAction;
}

void AdaptiveCards::Image::SetSelectAction(const std::shared_ptr<BaseActionElement> action)
{
    m_selectAction = action;
}
