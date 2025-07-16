#pragma once
#include "attribute/attribute_info.hpp"
#include "constant/cp_info.hpp"
#include "field/field_info.hpp"
#include "marco.hpp"
#include "method/method_info.hpp"
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

namespace mini {

class cp_info;
class interface;
class field_info;
class method_info;
class attribute_info;

// 类文件，由minijava的parser模块解析class文件创建
class classfile {
    friend class parser;

  public:
    classfile() = default;
    classfile(const classfile &) = delete;
    classfile(classfile &&) = delete;
    classfile &operator=(const classfile &) = delete;
    classfile &operator=(classfile &&) = delete;
    static classfile *create() = delete;

  public:
    // 从常量池取出index的cp_info，转成Class_info获取类名index
    // 根据类名index取出类名
    std::string getClassName(u2 index) const;
    // 根据索引从常量池中获取Utf8字符串
    std::string getUtf8(u2 index) const;
    // 从该类中取出主方法
    auto getMainMethod() const -> std::unique_ptr<attribute_info>;

  private:
    u4 magic_;
    u2 minor_version_;
    u2 major_version_;
    u2 constant_pool_count_;
    std::vector<std::unique_ptr<cp_info>> constant_pool_;

    u2 access_flags_;
    u2 this_class_;
    u2 super_class_;

    u2 interfaces_count_;
    std::vector<u2> interfaces_;

    u2 fields_count_;
    std::vector<std::unique_ptr<field_info>> fields_;

    u2 methods_count_;
    std::vector<std::unique_ptr<method_info>> methods_;

    u2 attributes_count_;
    std::vector<std::unique_ptr<attribute_info>> attributes_;
};

} // namespace mini
