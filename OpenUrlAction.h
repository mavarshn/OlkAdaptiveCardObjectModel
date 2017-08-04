#pragma once

#include "stdafx.h"
#include "BaseActionElement.h"
#include "Enums.h"

namespace AdaptiveCards
{
class OpenUrlAction : public BaseActionElement
{
public:
    OpenUrlAction();

    static std::shared_ptr<OpenUrlAction> Deserialize(const Mso::Json::value& root);
    static std::shared_ptr<OpenUrlAction> DeserializeFromString(const std::wstring& jsonString);

    virtual std::wstring Serialize();
    virtual Mso::Json::value SerializeToJsonValue();

    std::wstring GetUrl() const;
    void SetUrl(const std::wstring& value);
    
private:
    std::wstring m_url;
};
}