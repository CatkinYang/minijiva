#include "attribute/attribute_utils.hpp"
#include "attribute/code_attri_info.hpp"
#include "classReader.hpp"
#include "classfile.hpp"
namespace mini {

std::vector<std::unique_ptr<attribute_info>>
readAttributes(classReader &reader, u2 count, const classfile &cf) {
    std::vector<std::unique_ptr<attribute_info>> result;
    for (u2 i = 0; i < count; ++i) {
        u2 name_index = reader.readU2();
        u4 length = reader.readU4();

        std::string attrName;
        try {
            attrName = cf.getUtf8(name_index);
        } catch (...) {
            attrName = "<invalid name>";
        }

        std::unique_ptr<attribute_info> attr;

        if (attrName == "Code") {
            auto codeAttr = std::make_unique<code_attri>();
            codeAttr->attribute_name_index_ = name_index;
            codeAttr->attributes_length_ = length;
            codeAttr->readInfo(reader, cf);
            attr = std::move(codeAttr);
        } else {
            auto raw = std::make_unique<raw_attribute>();
            raw->attribute_name_index_ = name_index;
            raw->attributes_length_ = length;
            raw->readInfo(reader, cf);
            attr = std::move(raw);
        }
        result.push_back(std::move(attr));
    }
    return result;
}

} // namespace mini
