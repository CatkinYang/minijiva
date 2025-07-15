#include "accessflag/fieldAccFlg.hpp"
#include <vector>

namespace mini {

std::string fieldAccFlg::toString(u2 flags) {
    std::vector<std::string> result;

    if (flags & 0x0001)
        result.push_back("public");
    if (flags & 0x0002)
        result.push_back("private");
    if (flags & 0x0004)
        result.push_back("protected");
    if (flags & 0x0008)
        result.push_back("static");
    if (flags & 0x0010)
        result.push_back("final");
    if (flags & 0x0040)
        result.push_back("volatile");
    if (flags & 0x0080)
        result.push_back("transient");
    if (flags & 0x1000)
        result.push_back("synthetic");
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
