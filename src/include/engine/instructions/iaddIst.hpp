#pragma once
#include "engine/stack.hpp"
#include "engine/value.hpp"
#include "instruction.hpp"
#include "marco.hpp"
namespace mini {

class IaddInstruction : public instruction {
  public:
    IaddInstruction() {
        opCode = 0x60; // 操作码为 0x60 对应 iadd
    }

    void print() const override {
        std::cout << "IaddInstruction (opCode: " << std::hex << int(opCode)
                  << std::dec << ")" << std::endl;
    }

    void fun(StackFrameRef frame) override {
        // 从栈中弹出两个值并执行加法
        Value v1 = frame->popOperandStack();
        Value v2 = frame->popOperandStack();

        // 检查类型是否匹配
        if (v1.is(ValueType::INT) && v2.is(ValueType::INT)) {
            int result = v1.get<int>() + v2.get<int>();
            frame->pushOperandStack(Value(result)); // 将结果压回栈中
        } else if (v1.is(ValueType::FLOAT) && v2.is(ValueType::FLOAT)) {
            float result = v1.get<float>() + v2.get<float>();
            frame->pushOperandStack(Value(result)); // 将结果压回栈中
        } else if (v1.is(ValueType::LONG) && v2.is(ValueType::LONG)) {
            long long result = v1.get<long long>() + v2.get<long long>();
            frame->pushOperandStack(Value(result)); // 将结果压回栈中
        } else if (v1.is(ValueType::DOUBLE) && v2.is(ValueType::DOUBLE)) {
            double result = v1.get<double>() + v2.get<double>();
            frame->pushOperandStack(Value(result)); // 将结果压回栈中
        } else {
            throw std::runtime_error("Incompatible types for iadd operation");
        }
    }
};

} // namespace mini
