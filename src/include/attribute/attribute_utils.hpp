// attribute_utils.hpp
#pragma once
#include "attribute_info.hpp"
#include "classReader.hpp"
#include <memory>
#include <vector>

namespace mini {

/**
 * @brief 解析 attribute_info 数组
 *
 * @param reader 二进制读取器
 * @param count 属性数量
 * @return std::vector<std::unique_ptr<attribute_info>>
 */
inline std::vector<std::unique_ptr<attribute_info>>
readAttributes(classReader &reader, u2 count) {
    std::vector<std::unique_ptr<attribute_info>> result;
    for (u2 i = 0; i < count; ++i) {
        auto attr = std::make_unique<attribute_info>();
        attr->attribute_name_index_ = reader.readU2();
        attr->attributes_length_ = reader.readU4();
        attr->info_.resize(attr->attributes_length_);
        for (u4 j = 0; j < attr->attributes_length_; ++j) {
            attr->info_[j] = reader.readU1();
        }
        result.push_back(std::move(attr));
    }
    return result;
}

} // namespace mini
