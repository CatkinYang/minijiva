#include "classfile.hpp"
#include "constant/cp_info.hpp" // 确保定义了 cp_info 及其子类
#include <stdexcept>

namespace mini {

std::string classfile::getClassName(u2 index) const {
    // 索引超过了常量池大小
    if (index == 0 || index >= constant_pool_.size() + 1)
        throw std::runtime_error("Invalid constant pool index: " +
                                 std::to_string(index));
    // 获取Class 常量信息
    auto *cls_info =
        dynamic_cast<CONSTANT_Class_info *>(constant_pool_[index - 1].get());
    if (!cls_info)
        throw std::runtime_error("Expected CONSTANT_Class_info at index " +
                                 std::to_string(index));
    // 获取cls常量名字的索引
    u2 name_index = cls_info->name_index;
    // 获取cls常量名
    auto *utf8_info = dynamic_cast<CONSTANT_Utf8_info *>(
        constant_pool_[name_index - 1].get());
    if (!utf8_info)
        throw std::runtime_error("Expected CONSTANT_Utf8_info at index " +
                                 std::to_string(name_index));

    return utf8_info->value;
}

std::string classfile::getUtf8(u2 index) const {
    if (index == 0 || index > constant_pool_.size())
        throw std::runtime_error("Invalid constant pool index");

    auto *utf8 =
        dynamic_cast<CONSTANT_Utf8_info *>(constant_pool_[index - 1].get());
    if (!utf8)
        throw std::runtime_error("Expected Utf8 at index " +
                                 std::to_string(index));

    return utf8->value;
}

} // namespace mini
