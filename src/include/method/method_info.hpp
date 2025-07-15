#pragma once
#include "attribute/attribute_info.hpp"
#include "marco.hpp"
#include <vector>
namespace mini {
class method_info {
  public:
    u2 access_flags_;
    u2 name_index_;
    u2 descriptor_index_;
    u2 attributes_count_;
    std::vector<std::unique_ptr<mini::attribute_info>> attributes_;
};
} // namespace mini
