#pragma once
#include "classReader.hpp"
#include "classfile.hpp"
#include <memory>
#include <vector>

namespace mini {

class attribute_info;
class classfile;
class classReader;

std::vector<std::unique_ptr<attribute_info>>
readAttributes(classReader &reader, u2 count, const classfile &cf);

} // namespace mini
