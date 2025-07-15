#include "attribute/attribute_info.hpp"
#include "classfile.hpp"
#include <string>

namespace mini {

void attribute_info::print(std::ostream &os, const classfile &cf) const {
    try {
        std::string name = cf.getUtf8(attribute_name_index_);
        os << "  Attribute: " << name << " (length=" << attributes_length_
           << ") [raw]\n";
    } catch (...) {
        os << "  Attribute: <unknown name index " << attribute_name_index_
           << ">\n";
    }
}

} // namespace mini
