#pragma once

#include "stdafx.h"
#include "BaseActionElement.h"
#include "BaseCardElement.h"
#include "Enums.h"

namespace AdaptiveCards
{
class Image : public BaseCardElement
{
public:
    Image();
    Image(SeparationStyle separationStyle,
        const std::wstring& speak,
        std::wstring uri,
        ImageStyle imageStyle,
        ImageSize imageSize,
        std::wstring altText,
        HorizontalAlignment hAlignment);

    static std::shared_ptr<Image> Deserialize(const Mso::Json::value& root);
    static std::shared_ptr<Image> DeserializeFromString(const std::wstring& jsonString);

    virtual std::wstring Serialize();
    virtual Mso::Json::value SerializeToJsonValue();

    std::wstring GetUrl() const;
    void SetUrl(const std::wstring& value);

    ImageStyle GetImageStyle() const;
    void SetImageStyle(const ImageStyle value);

    ImageSize GetImageSize() const;
    void SetImageSize(const ImageSize value);

    std::wstring GetAltText() const;
    void SetAltText(const std::wstring& value);

    HorizontalAlignment GetHorizontalAlignment() const;
    void SetHorizontalAlignment(const HorizontalAlignment value);

    std::shared_ptr<BaseActionElement> GetSelectAction() const;
    void SetSelectAction(const std::shared_ptr<BaseActionElement> action);

private:
    std::wstring m_url;
    ImageStyle m_imageStyle;
    ImageSize m_imageSize;
    std::wstring m_altText;
    HorizontalAlignment m_hAlignment;
    std::shared_ptr<BaseActionElement> m_selectAction;
};
}
