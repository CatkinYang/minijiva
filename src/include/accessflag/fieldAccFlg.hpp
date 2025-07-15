#pragma once
#include "marco.hpp"
#include <string>
namespace mini {

class fieldAccFlg {
  public:
    fieldAccFlg() = delete;
    static std::string toString(u2 flags);
};

} // namespace mini
