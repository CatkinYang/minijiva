#include "accessflag/classAccFlg.hpp"
#include <vector>

namespace mini {

std::string classAccFlg::toString(u2 flags) {
    std::vector<std::string> result;

    if (flags & 0x0001)
        result.push_back("public");
    if (flags & 0x0010)
        result.push_back("final");
    if (flags & 0x0020)
        result.push_back("super");
    if (flags & 0x0200)
        result.push_back("interface");
    if (flags & 0x0400)
        result.push_back("abstract");
    if (flags & 0x1000)
        result.push_back("synthetic");
    if (flags & 0x2000)
        result.push_back("annotation");
    if (flags & 0x4000)
        result.push_back("enum");

    std::string joined;
    for (size_t i = 0; i < result.size(); ++i) {
        joined += result[i];
        if (i + 1 < result.size())
            joined += " ";
    }
    return joined;
}

} // namespace mini
