#pragma once
#include "attribute_info.hpp"
#include "attribute_utils.hpp"
#include "classReader.hpp"
#include "classfile.hpp"
#include "exception_attri_info.hpp"
#include <memory>
#include <vector>

namespace mini {

// Code属性表
class code_attri : public attribute_info {
  public:
    u2 max_stack_;
    u2 max_locals_;
    u4 code_length_;
    std::vector<u1> code_;
    u2 exception_table_length_;
    std::vector<std::unique_ptr<exceptable_info>> exception_table_;
    u2 attributes_count_;
    std::vector<std::unique_ptr<attribute_info>> attributes_;

    void readInfo(classReader &reader, const classfile &cf) override {
        max_stack_ = reader.readU2();
        max_locals_ = reader.readU2();
        code_length_ = reader.readU4();

        code_.resize(code_length_);
        for (u4 i = 0; i < code_length_; ++i)
            code_[i] = reader.readU1();

        exception_table_length_ = reader.readU2();
        exception_table_.resize(exception_table_length_);
        for (u2 i = 0; i < exception_table_length_; ++i) {
            auto e = std::make_unique<exceptable_info>();
            e->start_pc_ = reader.readU2();
            e->end_pc_ = reader.readU2();
            e->handler_pc_ = reader.readU2();
            e->catch_type_ = reader.readU2();
            exception_table_[i] = std::move(e);
        }

        attributes_count_ = reader.readU2();
        attributes_ = readAttributes(reader, attributes_count_, cf);
    }

    void print(std::ostream &os, const classfile &cf) const override {
        os << "  Attribute: Code\n";
        os << "    max_stack = " << max_stack_
           << ", max_locals = " << max_locals_
           << ", code_length = " << code_length_ << "\n";
        os << "    code = [";
        for (size_t i = 0; i < code_.size(); ++i) {
            os << std::hex << static_cast<int>(code_[i]);
            if (i + 1 < code_.size())
                os << " ";
        }
        os << "]\n";
        os << "    exception_table_length = " << exception_table_length_
           << "\n";
        os << "    attributes_count = " << attributes_count_ << "\n";
    }
};

} // namespace mini
