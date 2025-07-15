#pragma once
#include "marco.hpp"
#include <vector>
namespace mini {

class attribute_info {
  public:
    u2 attribute_name_index_;
    u4 attributes_length_;
    std::vector<u1> info_;
};

} // namespace mini
