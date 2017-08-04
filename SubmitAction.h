#pragma once

#include "stdafx.h"
#include "BaseActionElement.h"
#include "Enums.h"

namespace AdaptiveCards
{
class SubmitAction : public BaseActionElement
{
public:
    SubmitAction();

    std::wstring GetDataJson() const;
    void SetDataJson(const std::wstring& value);

    static std::shared_ptr<SubmitAction> Deserialize(const Mso::Json::value& root);
    static std::shared_ptr<SubmitAction> DeserializeFromString(const std::wstring& jsonString);

    virtual std::wstring Serialize();
    virtual Mso::Json::value SerializeToJsonValue();

private:
    std::wstring m_dataJson;
};
}