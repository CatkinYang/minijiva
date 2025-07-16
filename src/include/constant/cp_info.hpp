#pragma once

#include "classReader.hpp"
#include "marco.hpp"
#include <iostream>
#include <memory>
#include <string>

namespace mini {

enum ConstantTag : u1 {
    CONSTANT_Utf8 = 1,
    CONSTANT_Integer = 3,
    CONSTANT_Float = 4,
    CONSTANT_Long = 5,
    CONSTANT_Double = 6,
    CONSTANT_Class = 7,
    CONSTANT_String = 8,
    CONSTANT_Fieldref = 9,
    CONSTANT_Methodref = 10,
    CONSTANT_InterfaceMethodref = 11,
    CONSTANT_NameAndType = 12,
    CONSTANT_MethodHandle = 15,
    CONSTANT_MethodType = 16,
    CONSTANT_Dynamic = 17,
    CONSTANT_InvokeDynamic = 18,
    CONSTANT_Module = 19,
    CONSTANT_Package = 20,
};

// 常量基类
// read： 根据不同tag创建不同的constant
class cp_info {
  public:
    virtual ~cp_info() = default;
    virtual void print() const = 0;
    static std::unique_ptr<cp_info> read(u1 tag, classReader &reader);
};

class CONSTANT_Utf8_info : public cp_info {
  public:
    u2 length;
    std::string value;

    CONSTANT_Utf8_info(u2 length, std::string value);
    void print() const override;
};

class CONSTANT_Integer_info : public cp_info {
  public:
    u4 bytes;

    explicit CONSTANT_Integer_info(u4 bytes);
    void print() const override;
};

class CONSTANT_Float_info : public cp_info {
  public:
    u4 bytes;

    explicit CONSTANT_Float_info(u4 bytes);
    void print() const override;
};

class CONSTANT_Long_info : public cp_info {
  public:
    u4 high_bytes;
    u4 low_bytes;

    CONSTANT_Long_info(u4 high_bytes, u4 low_bytes);
    void print() const override;
};

class CONSTANT_Double_info : public cp_info {
  public:
    u4 high_bytes;
    u4 low_bytes;

    CONSTANT_Double_info(u4 high_bytes, u4 low_bytes);
    void print() const override;
};

class CONSTANT_Class_info : public cp_info {
  public:
    u2 name_index;

    explicit CONSTANT_Class_info(u2 name_index);
    void print() const override;
};

class CONSTANT_String_info : public cp_info {
  public:
    u2 string_index;

    explicit CONSTANT_String_info(u2 string_index);
    void print() const override;
};

class CONSTANT_Fieldref_info : public cp_info {
  public:
    u2 class_index;
    u2 name_and_type_index;

    CONSTANT_Fieldref_info(u2 class_index, u2 name_and_type_index);
    void print() const override;
};

class CONSTANT_Methodref_info : public cp_info {
  public:
    u2 class_index;
    u2 name_and_type_index;

    CONSTANT_Methodref_info(u2 class_index, u2 name_and_type_index);
    void print() const override;
};

class CONSTANT_InterfaceMethodref_info : public cp_info {
  public:
    u2 class_index;
    u2 name_and_type_index;

    CONSTANT_InterfaceMethodref_info(u2 class_index, u2 name_and_type_index);
    void print() const override;
};

class CONSTANT_NameAndType_info : public cp_info {
  public:
    u2 name_index;
    u2 descriptor_index;

    CONSTANT_NameAndType_info(u2 name_index, u2 descriptor_index);
    void print() const override;
};

class CONSTANT_MethodHandle_info : public cp_info {
  public:
    u1 reference_kind;
    u2 reference_index;

    CONSTANT_MethodHandle_info(u1 reference_kind, u2 reference_index);
    void print() const override;
};

class CONSTANT_MethodType_info : public cp_info {
  public:
    u2 descriptor_index;

    explicit CONSTANT_MethodType_info(u2 descriptor_index);
    void print() const override;
};

class CONSTANT_Dynamic_info : public cp_info {
  public:
    u2 bootstrap_method_attr_index;
    u2 name_and_type_index;

    CONSTANT_Dynamic_info(u2 bootstrap_method_attr_index,
                          u2 name_and_type_index);
    void print() const override;
};

class CONSTANT_InvokeDynamic_info : public cp_info {
  public:
    u2 bootstrap_method_attr_index;
    u2 name_and_type_index;

    CONSTANT_InvokeDynamic_info(u2 bootstrap_method_attr_index,
                                u2 name_and_type_index);
    void print() const override;
};

class CONSTANT_Module_info : public cp_info {
  public:
    u2 name_index;

    explicit CONSTANT_Module_info(u2 name_index);
    void print() const override;
};

class CONSTANT_Package_info : public cp_info {
  public:
    u2 name_index;

    explicit CONSTANT_Package_info(u2 name_index);
    void print() const override;
};

} // namespace mini
