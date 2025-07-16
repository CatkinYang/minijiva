#pragma once
#include "attribute/attribute_info.hpp"
#include "classfile.hpp"
#include "engine/stack.hpp"
#include "marco.hpp"
#include <vector>
namespace mini {
// 方法表
class method_info {
  public:
    u2 access_flags_;
    u2 name_index_;
    u2 descriptor_index_;
    u2 attributes_count_;
    // Code属性
    std::vector<std::unique_ptr<mini::attribute_info>> attributes_;
    // 打印method_info的attribute信息
    void print_attri(const classfile &cf) const {
        for (u2 i = 0; i < attributes_count_; ++i) {
            const auto &attr = attributes_[i];
            attr->print(std::cout, cf);
        }
    }
    static auto methodToStackFrame(method_info method) -> StackFrameRef {
        return nullptr;
    }
};
} // namespace mini
