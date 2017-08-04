#pragma once

#include "stdafx.h"
#include "Enums.h"
#include "Image.h"
#include "BaseCardElement.h"

namespace AdaptiveCards
{
class BaseCardElement;
    class ImageSet : public BaseCardElement
    {
        public:
        ImageSet();
        ImageSet(SeparationStyle separation, std::wstring speak);
        ImageSet(SeparationStyle separation, const std::wstring& speak, std::vector<std::shared_ptr<Image>>& images);

        virtual std::wstring Serialize();
        virtual Mso::Json::value SerializeToJsonValue();

        ImageSize GetImageSize() const;
        void SetImageSize(const ImageSize value);

        std::vector<std::shared_ptr<Image>>& GetImages();
        const std::vector<std::shared_ptr<Image>>& GetImages() const;
        static std::shared_ptr<ImageSet> Deserialize(const Mso::Json::value& root);
        static std::shared_ptr<ImageSet> DeserializeFromString(const std::wstring& jsonString);

        private:
        std::vector<std::shared_ptr<Image>> m_images;
        ImageSize m_imageSize;
    };
}