#pragma once
#include "classReader.hpp"
#include "classfile.hpp"
#include <memory>
#include <vector>

namespace mini {

class attribute_info;
class classfile;
class classReader;

// 读取count个属性并返回vector数组
// 解析属性名，根据属性名生成不同的属性表对象
std::vector<std::unique_ptr<attribute_info>>
readAttributes(classReader &reader, u2 count, const classfile &cf);

} // namespace mini
