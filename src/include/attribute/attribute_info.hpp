#pragma once
#include "classReader.hpp"
#include "marco.hpp"
#include <vector>
namespace mini {

class classfile;

// 属性表 基类
class attribute_info {
  public:
    u2 attribute_name_index_;
    u4 attributes_length_;
    // 虚函数，子类根据类型的不同，进行不同的读取
    virtual void readInfo(classReader &reader, const classfile &cf) = 0;
    virtual ~attribute_info() = default;
    // 打印不同的输出信息
    virtual void print(std::ostream &os, const classfile &cf) const = 0;
};

// 暂时的处理方案，后面扩展继承
// 无法解析的,统一生成raw_attribute对象 字节流直接存到info_里
class raw_attribute : public attribute_info {
  public:
    std::vector<u1> info_;
    void readInfo(classReader &reader, const classfile &cf) override {
        info_.resize(attributes_length_);
        for (u4 i = 0; i < attributes_length_; ++i)
            info_[i] = reader.readU1();
    }

    void print(std::ostream &os, const classfile &cf) const override;
};

} // namespace mini
