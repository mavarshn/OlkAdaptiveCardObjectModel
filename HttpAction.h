#pragma once

#include "stdafx.h"
#include "BaseActionElement.h"
#include "Enums.h"

namespace AdaptiveCards
{
class HttpAction : public BaseActionElement
{
public:
    HttpAction();

    static std::shared_ptr<HttpAction> Deserialize(const Mso::Json::value& root);
    static std::shared_ptr<HttpAction> DeserializeFromString(const std::wstring& jsonString);

    virtual std::wstring Serialize();
    virtual Mso::Json::value SerializeToJsonValue();

    std::wstring GetUrl() const;
    void SetUrl(const std::wstring value);

    std::wstring GetMethod() const;
    void SetMethod(const std::wstring value);

    std::wstring GetBody() const;
    void SetBody(const std::wstring value);

private:
    std::wstring m_method;
    std::wstring m_body;
    std::wstring m_url;
};
}