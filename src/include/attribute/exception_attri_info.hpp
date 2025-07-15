#pragma once
#include "attribute/attribute_info.hpp"

namespace mini {

class exceptable_info {
  public:
    u2 start_pc_;
    u2 end_pc_;
    u2 handler_pc_;
    u2 catch_type_;
};

class exception_attri_info : public attribute_info {
  public:
    u2 exception_num_;
    std::vector<u2> exception_index_table;

    void readInfo(classReader &reader, const classfile &cf) override {};

    void print(std::ostream &os, const classfile &cf) const override {}
};

} // namespace mini
