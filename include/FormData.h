#pragma once

#include <memory>

class FormData;
typedef std::shared_ptr<FormData> FormDataPtr;

class FormData
{
public:
    FormData() = default;
    ~FormData() = default;
    std::string xpath_;

};