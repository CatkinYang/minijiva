#pragma once
#include "marco.hpp"
#include <string>
namespace mini {

class classAccFlg {
  public:
    classAccFlg() = delete;
    // 将 access_flags 转为可读字符串
    static std::string toString(u2 flags);
};

} // namespace mini
