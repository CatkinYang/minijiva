#pragma once
#include "engine/stack.hpp"
#include "engine/value.hpp"
#include "instruction.hpp"
#include "marco.hpp"
namespace mini {
// 基本的 iload 指令（通过局部变量索引加载）
class IloadInstruction : public instruction {
  public:
    u1 index; // 局部变量索引

    IloadInstruction(u1 idx) : index(idx) {
        opCode = 0x15; // 操作码为 0x15 对应 iload
    }

    void print() const override {
        std::cout << "IloadInstruction (opCode: " << std::hex << int(opCode)
                  << std::dec << ", index: " << int(index) << ")" << std::endl;
    }

    void fun(StackFrameRef frame) override {
        Value value = frame->getLocalVar(index); // 从局部变量表加载值
        frame->pushOperandStack(value);          // 将值压入操作数栈
    }
};

// iload_0 指令（从局部变量表加载第 0 个局部变量）
class Iload0Instruction : public instruction {
  public:
    Iload0Instruction() {
        opCode = 0x1A; // 操作码为 0x1A 对应 iload_0
    }

    void print() const override {
        std::cout << "Iload0Instruction (opCode: " << std::hex << int(opCode)
                  << std::dec << ")" << std::endl;
    }

    void fun(StackFrameRef frame) override {
        Value value = frame->getLocalVar(0); // 从局部变量表加载第 0 个局部变量
        frame->pushOperandStack(value);      // 将值压入操作数栈
    }
};

// iload_1 指令（从局部变量表加载第 1 个局部变量）
class Iload1Instruction : public instruction {
  public:
    Iload1Instruction() {
        opCode = 0x1B; // 操作码为 0x1B 对应 iload_1
    }

    void print() const override {
        std::cout << "Iload1Instruction (opCode: " << std::hex << int(opCode)
                  << std::dec << ")" << std::endl;
    }

    void fun(StackFrameRef frame) override {
        Value value = frame->getLocalVar(1); // 从局部变量表加载第 1 个局部变量
        frame->pushOperandStack(value);      // 将值压入操作数栈
    }
};

// iload_2 指令（从局部变量表加载第 2 个局部变量）
class Iload2Instruction : public instruction {
  public:
    Iload2Instruction() {
        opCode = 0x1C; // 操作码为 0x1C 对应 iload_2
    }

    void print() const override {
        std::cout << "Iload2Instruction (opCode: " << std::hex << int(opCode)
                  << std::dec << ")" << std::endl;
    }

    void fun(StackFrameRef frame) override {
        Value value = frame->getLocalVar(2); // 从局部变量表加载第 2 个局部变量
        frame->pushOperandStack(value);      // 将值压入操作数栈
    }
};

// iload_3 指令（从局部变量表加载第 3 个局部变量）
class Iload3Instruction : public instruction {
  public:
    Iload3Instruction() {
        opCode = 0x1D; // 操作码为 0x1D 对应 iload_3
    }

    void print() const override {
        std::cout << "Iload3Instruction (opCode: " << std::hex << int(opCode)
                  << std::dec << ")" << std::endl;
    }

    void fun(StackFrameRef frame) override {
        Value value = frame->getLocalVar(3); // 从局部变量表加载第 3 个局部变量
        frame->pushOperandStack(value);      // 将值压入操作数栈
    }
};
} // namespace mini
