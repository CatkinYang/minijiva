#include "constant/cp_info.hpp"

namespace mini {

std::unique_ptr<cp_info> cp_info::read(u1 tag, classReader &r) {
    switch (tag) {
    case CONSTANT_Utf8: {
        u2 len = r.readU2();
        std::string val(len, '\0');
        for (u2 i = 0; i < len; ++i)
            val[i] = r.readU1();
        return std::make_unique<CONSTANT_Utf8_info>(len, std::move(val));
    }
    case CONSTANT_Integer:
        return std::make_unique<CONSTANT_Integer_info>(r.readU4());
    case CONSTANT_Float:
        return std::make_unique<CONSTANT_Float_info>(r.readU4());
    case CONSTANT_Long:
        return std::make_unique<CONSTANT_Long_info>(r.readU4(), r.readU4());
    case CONSTANT_Double:
        return std::make_unique<CONSTANT_Double_info>(r.readU4(), r.readU4());
    case CONSTANT_Class:
        return std::make_unique<CONSTANT_Class_info>(r.readU2());
    case CONSTANT_String:
        return std::make_unique<CONSTANT_String_info>(r.readU2());
    case CONSTANT_Fieldref:
        return std::make_unique<CONSTANT_Fieldref_info>(r.readU2(), r.readU2());
    case CONSTANT_Methodref:
        return std::make_unique<CONSTANT_Methodref_info>(r.readU2(),
                                                         r.readU2());
    case CONSTANT_InterfaceMethodref:
        return std::make_unique<CONSTANT_InterfaceMethodref_info>(r.readU2(),
                                                                  r.readU2());
    case CONSTANT_NameAndType:
        return std::make_unique<CONSTANT_NameAndType_info>(r.readU2(),
                                                           r.readU2());
    case CONSTANT_MethodHandle:
        return std::make_unique<CONSTANT_MethodHandle_info>(r.readU1(),
                                                            r.readU2());
    case CONSTANT_MethodType:
        return std::make_unique<CONSTANT_MethodType_info>(r.readU2());
    case CONSTANT_Dynamic:
        return std::make_unique<CONSTANT_Dynamic_info>(r.readU2(), r.readU2());
    case CONSTANT_InvokeDynamic:
        return std::make_unique<CONSTANT_InvokeDynamic_info>(r.readU2(),
                                                             r.readU2());
    case CONSTANT_Module:
        return std::make_unique<CONSTANT_Module_info>(r.readU2());
    case CONSTANT_Package:
        return std::make_unique<CONSTANT_Package_info>(r.readU2());
    default:
        throw std::runtime_error("Unknown constant pool tag: " +
                                 std::to_string(tag));
    }
}

CONSTANT_Utf8_info::CONSTANT_Utf8_info(u2 length, std::string value)
    : length(length), value(std::move(value)) {}

CONSTANT_Integer_info::CONSTANT_Integer_info(u4 bytes) : bytes(bytes) {}

CONSTANT_Float_info::CONSTANT_Float_info(u4 bytes) : bytes(bytes) {}

CONSTANT_Long_info::CONSTANT_Long_info(u4 high_bytes, u4 low_bytes)
    : high_bytes(high_bytes), low_bytes(low_bytes) {}

CONSTANT_Double_info::CONSTANT_Double_info(u4 high_bytes, u4 low_bytes)
    : high_bytes(high_bytes), low_bytes(low_bytes) {}

CONSTANT_Class_info::CONSTANT_Class_info(u2 name_index)
    : name_index(name_index) {}

CONSTANT_String_info::CONSTANT_String_info(u2 string_index)
    : string_index(string_index) {}

CONSTANT_Fieldref_info::CONSTANT_Fieldref_info(u2 class_index,
                                               u2 name_and_type_index)
    : class_index(class_index), name_and_type_index(name_and_type_index) {}

CONSTANT_Methodref_info::CONSTANT_Methodref_info(u2 class_index,
                                                 u2 name_and_type_index)
    : class_index(class_index), name_and_type_index(name_and_type_index) {}

CONSTANT_InterfaceMethodref_info::CONSTANT_InterfaceMethodref_info(
    u2 class_index, u2 name_and_type_index)
    : class_index(class_index), name_and_type_index(name_and_type_index) {}

CONSTANT_NameAndType_info::CONSTANT_NameAndType_info(u2 name_index,
                                                     u2 descriptor_index)
    : name_index(name_index), descriptor_index(descriptor_index) {}

CONSTANT_MethodHandle_info::CONSTANT_MethodHandle_info(u1 reference_kind,
                                                       u2 reference_index)
    : reference_kind(reference_kind), reference_index(reference_index) {}

CONSTANT_MethodType_info::CONSTANT_MethodType_info(u2 descriptor_index)
    : descriptor_index(descriptor_index) {}

CONSTANT_Dynamic_info::CONSTANT_Dynamic_info(u2 bootstrap_method_attr_index,
                                             u2 name_and_type_index)
    : bootstrap_method_attr_index(bootstrap_method_attr_index),
      name_and_type_index(name_and_type_index) {}

CONSTANT_InvokeDynamic_info::CONSTANT_InvokeDynamic_info(
    u2 bootstrap_method_attr_index, u2 name_and_type_index)
    : bootstrap_method_attr_index(bootstrap_method_attr_index),
      name_and_type_index(name_and_type_index) {}

CONSTANT_Module_info::CONSTANT_Module_info(u2 name_index)
    : name_index(name_index) {}

CONSTANT_Package_info::CONSTANT_Package_info(u2 name_index)
    : name_index(name_index) {}

void CONSTANT_Utf8_info::print() const {
    std::cout << "Utf8: " << value << "\n";
}

void CONSTANT_Integer_info::print() const {
    std::cout << "Integer: " << bytes << "\n";
}

void CONSTANT_Float_info::print() const {
    std::cout << "Float: " << bytes << "\n";
}

void CONSTANT_Long_info::print() const {
    uint64_t val = ((uint64_t)high_bytes << 32) | low_bytes;
    std::cout << "Long: " << val << "\n";
}

void CONSTANT_Double_info::print() const {
    uint64_t val = ((uint64_t)high_bytes << 32) | low_bytes;
    std::cout << "Double: " << val << "\n";
}

void CONSTANT_Class_info::print() const {
    std::cout << "Class name_index: " << name_index << "\n";
}

void CONSTANT_String_info::print() const {
    std::cout << "String index: " << string_index << "\n";
}

void CONSTANT_Fieldref_info::print() const {
    std::cout << "Fieldref: class_index=" << class_index
              << ", name_and_type_index=" << name_and_type_index << "\n";
}

void CONSTANT_Methodref_info::print() const {
    std::cout << "Methodref: class_index=" << class_index
              << ", name_and_type_index=" << name_and_type_index << "\n";
}

void CONSTANT_InterfaceMethodref_info::print() const {
    std::cout << "InterfaceMethodref: class_index=" << class_index
              << ", name_and_type_index=" << name_and_type_index << "\n";
}

void CONSTANT_NameAndType_info::print() const {
    std::cout << "NameAndType: name_index=" << name_index
              << ", desc_index=" << descriptor_index << "\n";
}

void CONSTANT_MethodHandle_info::print() const {
    std::cout << "MethodHandle: kind=" << static_cast<int>(reference_kind)
              << ", index=" << reference_index << "\n";
}

void CONSTANT_MethodType_info::print() const {
    std::cout << "MethodType: desc_index=" << descriptor_index << "\n";
}

void CONSTANT_Dynamic_info::print() const {
    std::cout << "Dynamic: bsm_attr_index=" << bootstrap_method_attr_index
              << ", nt_index=" << name_and_type_index << "\n";
}

void CONSTANT_InvokeDynamic_info::print() const {
    std::cout << "InvokeDynamic: bsm_attr_index=" << bootstrap_method_attr_index
              << ", nt_index=" << name_and_type_index << "\n";
}

void CONSTANT_Module_info::print() const {
    std::cout << "Module name_index=" << name_index << "\n";
}

void CONSTANT_Package_info::print() const {
    std::cout << "Package name_index=" << name_index << "\n";
}

} // namespace mini
