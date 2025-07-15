#include "parser.hpp"
#include "accessflag/classAccFlg.hpp"
#include "attribute/attribute_info.hpp"
#include "attribute/attribute_utils.hpp"
#include <memory>
#include <numeric>

namespace mini {

std::unique_ptr<classfile> parser::fileToObject(std::string filename) {
    std::ifstream input(filename, std::ios::binary);
    if (!input.is_open()) {
        std::cerr << "Cannot open file: " << filename << std::endl;
        return nullptr;
    }

    classReader reader(input);
    auto cf = std::make_unique<classfile>();

    // 填充cf的魔数字段，并判断是否是class类型
    cf->magic_ = reader.readU4();
    // std::cout << std::hex << std::uppercase << cf->magic_ << std::endl;
    if (cf->magic_ != 0xCAFEBABE) {
        std::cerr << "Invalid class file format" << std::endl;
        return nullptr;
    } else { // 文件是class文件
        std::cout << "valid class file format" << std::endl;
    }

    // 填充版本号version
    cf->minor_version_ = reader.readU2();
    cf->major_version_ = reader.readU2();
    std::cout << "Version: " << cf->major_version_ << "." << cf->minor_version_
              << std::endl;

    // 常量池大小
    cf->constant_pool_count_ = reader.readU2();
    std::cout << "Constant pool count: " << cf->constant_pool_count_
              << std::endl;
    // 初始化常量池大小
    cf->constant_pool_.resize(cf->constant_pool_count_ - 1); // 从索引1开始
    // 读取常量池数据
    for (auto i = 1; i < cf->constant_pool_count_; ++i) {
        auto tag = reader.readU1();
        // 调用 cp_info 子类的工厂方法创建对应的常量数据
        auto entry = cp_info::read(tag, reader);
        cf->constant_pool_[i - 1] = std::move(entry);
        if (tag == CONSTANT_Long ||
            tag == CONSTANT_Double) { // Long / Double 占两个槽位
            ++i;
            if (i < cf->constant_pool_count_)
                cf->constant_pool_[i - 1] = nullptr; // 占位，不能使用
        }
    }
    std::cout << "Constant pool loaded successfully.\n";

    // 访问标志
    cf->access_flags_ = reader.readU2();
    std::cout << "Access Flags: 0x" << std::hex << cf->access_flags_ << " ("
              << classAccFlg::toString(cf->access_flags_) << ")" << std::dec
              << "\n";

    // 类、父类索引
    cf->this_class_ = reader.readU2();
    cf->super_class_ = reader.readU2();
    try {
        std::string thisName = cf->getClassName(cf->this_class_);
        std::string superName = (cf->super_class_ != 0)
                                    ? cf->getClassName(cf->super_class_)
                                    : "(none)";
        std::cout << "This class: " << thisName << "\n";
        std::cout << "Super class: " << superName << "\n";
    } catch (const std::exception &ex) {
        std::cerr << "Error resolving class names: " << ex.what() << "\n";
    }

    // 接口索引数量、集合
    cf->interfaces_count_ = reader.readU2();
    cf->interfaces_.resize(cf->interfaces_count_);
    for (u2 i = 0; i < cf->interfaces_count_; ++i) {
        cf->interfaces_[i] = reader.readU2();
    }
    std::cout << "Interfaces count: " << cf->interfaces_count_ << "\n";
    for (auto i = 0; i < cf->interfaces_count_; ++i) {
        try {
            std::string ifaceName = cf->getClassName(cf->interfaces_[i]);
            std::cout << "  Interface #" << i << ": " << ifaceName << "\n";
        } catch (const std::exception &ex) {
            std::cerr << "  Interface #" << i << ": error - " << ex.what()
                      << "\n";
        }
    }

    // 字段表数量、字段表
    cf->fields_count_ = reader.readU2();
    cf->fields_.resize(cf->fields_count_);
    std::cout << "Fields count: " << cf->fields_count_ << "\n";
    for (auto i = 0; i < cf->fields_count_; ++i) {
        auto field = std::make_unique<field_info>();
        field->access_flags_ = reader.readU2();
        field->name_index_ = reader.readU2();
        field->descriptor_index = reader.readU2();
        field->attributes_count_ = reader.readU2();
        field->attributes_ =
            readAttributes(reader, field->attributes_count_, *cf.get());
        try {
            std::string fieldName = cf->getUtf8(field->name_index_);
            std::string descriptor = cf->getUtf8(field->descriptor_index);
            std::cout << "  Field #" << i << ": " << fieldName << " : "
                      << descriptor << "\n";
        } catch (const std::exception &e) {
            std::cerr << "  Field #" << i << " parse failed: " << e.what()
                      << "\n";
        }
        cf->fields_[i] = std::move(field);
    }

    // 方法表
    cf->methods_count_ = reader.readU2();
    cf->methods_.resize(cf->methods_count_);
    std::cout << "Methods count: " << cf->methods_count_ << std::endl;
    for (u2 i = 0; i < cf->methods_count_; ++i) {
        auto method = std::make_unique<method_info>();
        method->access_flags_ = reader.readU2();
        method->name_index_ = reader.readU2();
        method->descriptor_index_ = reader.readU2();
        method->attributes_count_ = reader.readU2();
        method->attributes_ =
            readAttributes(reader, method->attributes_count_, *cf);

        try {
            std::string methodName = cf->getUtf8(method->name_index_);
            std::string descriptor = cf->getUtf8(method->descriptor_index_);
            std::cout << "  Method #" << i << ": " << methodName << " "
                      << descriptor << "\n";
        } catch (const std::exception &e) {
            std::cerr << "  Method #" << i << " parse failed: " << e.what()
                      << "\n";
        }

        cf->methods_[i] = std::move(method);
    }

    // 属性表
    cf->attributes_count_ = reader.readU2();
    cf->attributes_ = readAttributes(reader, cf->attributes_count_, *cf.get());
    for (u2 i = 0; i < cf->attributes_count_; ++i) {
        const auto &attr = cf->attributes_[i];
        try {
            std::string attrName = cf->getUtf8(attr->attribute_name_index_);
            std::cout << "Attribute #" << i << ": " << attrName
                      << ", length = " << attr->attributes_length_ << "\n";
        } catch (const std::exception &e) {
            std::cerr << "  Attribute #" << i << " parse failed: " << e.what()
                      << "\n";
        }
    }
    for (u2 i = 0; i < cf->attributes_count_; ++i) {
        const auto &attr = cf->attributes_[i];
        attr->print(std::cout, *cf.get());
    }

    return cf;
}

} // namespace mini
