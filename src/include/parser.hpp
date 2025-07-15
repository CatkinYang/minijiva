#pragma once
#include "classReader.hpp"
#include "classfile.hpp"
#include <fstream>
#include <iostream>
#include <memory>
#include <string>

namespace mini {
// using cfptr = std::shared_ptr<mini::classfile>;
// 读取class文件，提供一个方法生成classfile对象

class parser {
  public:
    parser() = default;
    static std::unique_ptr<classfile> fileToObject(std::string filename);
};

} // namespace mini
