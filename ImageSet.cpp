#include "stdafx.h"
#include "ImageSet.h"
#include "ParseUtil.h"
#include "Image.h"

using namespace AdaptiveCards;

ImageSet::ImageSet() : 
    BaseCardElement(CardElementType::ImageSet),
    m_imageSize(ImageSize::Auto)
{
}

ImageSet::ImageSet(
    SeparationStyle separation,
    const std::wstring& speak,
    std::vector<std::shared_ptr<AdaptiveCards::Image>>& images) :
    BaseCardElement(CardElementType::ImageSet, separation, speak),
    m_images(images),
    m_imageSize(ImageSize::Default)
{
}

ImageSet::ImageSet(
    SeparationStyle separation,
    std::wstring speak) :
    BaseCardElement(CardElementType::ImageSet, separation, speak),
    m_imageSize(ImageSize::Auto)
{
}

ImageSize ImageSet::GetImageSize() const
{
    return m_imageSize;
}

void ImageSet::SetImageSize(const ImageSize value)
{
    m_imageSize = value;
}

const std::vector<std::shared_ptr<AdaptiveCards::Image>>& ImageSet::GetImages() const
{
    return m_images;
}

std::vector<std::shared_ptr<AdaptiveCards::Image>>& ImageSet::GetImages()
{
    return m_images;
}

std::wstring ImageSet::Serialize()
{
   
    return SerializeToJsonValue().to_string();
}

Mso::Json::value ImageSet::SerializeToJsonValue()
{
    Mso::Json::value root = BaseCardElement::SerializeToJsonValue();

    root[AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::ImageSize)] = Mso::Json::value(ImageSizeToString(GetImageSize()));

    std::wstring itemsPropertyName = AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::Images);
    root[itemsPropertyName] = Mso::Json::value::array();
    int i = 0;
    for (const auto& image : GetImages())
    {
        root[itemsPropertyName][i++] = image->SerializeToJsonValue();
    }

    return root;
}

std::shared_ptr<ImageSet> ImageSet::Deserialize(const Mso::Json::value& value)
{
    ParseUtil::ExpectTypeString(value, CardElementType::ImageSet);

    auto imageSet = BaseCardElement::Deserialize<ImageSet>(value);

    // Get ImageSize
    imageSet->m_imageSize = ParseUtil::GetEnumValue<ImageSize>(value, AdaptiveCardSchemaKey::ImageSize, ImageSize::Auto, ImageSizeFromString);

    // Parse Images
    auto imagesArray = ParseUtil::GetArray(value, AdaptiveCardSchemaKey::Images, true);
    std::vector<std::shared_ptr<AdaptiveCards::Image>> images;

    // Deserialize every image in the array
    for (auto & element : imagesArray)
    {
        auto image = AdaptiveCards::Image::Deserialize(element.second);
        if (image != nullptr)
        {
            images.push_back(image);
        }
    }

    imageSet->m_images = std::move(images);

    return imageSet;
}\

std::shared_ptr<ImageSet> ImageSet::DeserializeFromString(const std::wstring& jsonString)
{
    return ImageSet::Deserialize(ParseUtil::GetJsonValueFromString(jsonString));
}
