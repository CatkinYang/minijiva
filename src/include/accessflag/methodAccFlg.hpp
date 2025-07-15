#pragma once
#include "marco.hpp"
#include <string>
namespace mini {

class methodAccFlg {
  public:
    methodAccFlg() = delete;
    static std::string toString(u2 flags);
};

} // namespace mini
