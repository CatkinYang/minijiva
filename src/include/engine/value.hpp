#pragma once
#include <string>
#include <type_traits>
#include <variant>

namespace mini {

// 支持的值类型
enum class ValueType {
    BOOLEAN,
    BYTE,
    CHAR,
    SHORT,
    INT,
    FLOAT,
    LONG,
    DOUBLE,
    REFERENCE
};

// 存储的值类型（可以是基本类型或引用类型）
class Value {
  public:
    std::variant<bool, char, short, int, float, long long, double, std::string>
        value;
    ValueType type;

    // 构造函数
    Value(bool v) : value(v), type(ValueType::BOOLEAN) {}
    Value(char v) : value(v), type(ValueType::CHAR) {}
    Value(short v) : value(v), type(ValueType::SHORT) {}
    Value(int v) : value(v), type(ValueType::INT) {}
    Value(float v) : value(v), type(ValueType::FLOAT) {}
    Value(long long v) : value(v), type(ValueType::LONG) {}
    Value(double v) : value(v), type(ValueType::DOUBLE) {}
    Value(const std::string &v) : value(v), type(ValueType::REFERENCE) {}

    // 获取值
    template <typename T> T get() const { return std::get<T>(value); }

    // 类型检查
    bool is(ValueType t) const { return type == t; }

    // 打印值
    std::string toString() const {
        switch (type) {
        case ValueType::BOOLEAN:
            return std::to_string(std::get<bool>(value));
        case ValueType::CHAR:
            return std::string(1, std::get<char>(value));
        case ValueType::SHORT:
            return std::to_string(std::get<short>(value));
        case ValueType::INT:
            return std::to_string(std::get<int>(value));
        case ValueType::FLOAT:
            return std::to_string(std::get<float>(value));
        case ValueType::LONG:
            return std::to_string(std::get<long long>(value));
        case ValueType::DOUBLE:
            return std::to_string(std::get<double>(value));
        case ValueType::REFERENCE:
            return std::get<std::string>(value);
        default:
            return "Unknown";
        }
    }
};
} // namespace mini
