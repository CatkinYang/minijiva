#pragma once
#include "engine/stack.hpp"
#include "engine/value.hpp"
#include "instruction.hpp"
#include "marco.hpp"
namespace mini {
// iconst_m1 指令（将常量 -1 压入操作数栈）
class IconstM1Instruction : public instruction {
  public:
    IconstM1Instruction() {
        opCode = 0x02; // 操作码为 0x02 对应 iconst_m1
    }
    void print() const override {
        std::cout << "IconstM1Instruction (opCode: " << std::hex << int(opCode)
                  << std::dec << ")" << std::endl;
    }
    void fun(StackFrameRef frame) override {
        frame->pushOperandStack(Value(-1)); // 将常量 -1 压入操作数栈
    }
};

// iconst_0 指令（将常量 0 压入操作数栈）
class Iconst0Instruction : public instruction {
  public:
    Iconst0Instruction() {
        opCode = 0x03; // 操作码为 0x03 对应 iconst_0
    }
    void print() const override {
        std::cout << "Iconst0Instruction (opCode: " << std::hex << int(opCode)
                  << std::dec << ")" << std::endl;
    }
    void fun(StackFrameRef frame) override {
        frame->pushOperandStack(Value(0)); // 将常量 0 压入操作数栈
    }
};

// iconst_1 指令（将常量 1 压入操作数栈）
class Iconst1Instruction : public instruction {
  public:
    Iconst1Instruction() {
        opCode = 0x04; // 操作码为 0x04 对应 iconst_1
    }
    void print() const override {
        std::cout << "Iconst1Instruction (opCode: " << std::hex << int(opCode)
                  << std::dec << ")" << std::endl;
    }
    void fun(StackFrameRef frame) override {
        frame->pushOperandStack(Value(1)); // 将常量 1 压入操作数栈
    }
};

// iconst_2 指令（将常量 2 压入操作数栈）
class Iconst2Instruction : public instruction {
  public:
    Iconst2Instruction() {
        opCode = 0x05; // 操作码为 0x05 对应 iconst_2
    }
    void print() const override {
        std::cout << "Iconst2Instruction (opCode: " << std::hex << int(opCode)
                  << std::dec << ")" << std::endl;
    }
    void fun(StackFrameRef frame) override {
        frame->pushOperandStack(Value(2)); // 将常量 2 压入操作数栈
    }
};

// iconst_3 指令（将常量 3 压入操作数栈）
class Iconst3Instruction : public instruction {
  public:
    Iconst3Instruction() {
        opCode = 0x06; // 操作码为 0x06 对应 iconst_3
    }
    void print() const override {
        std::cout << "Iconst3Instruction (opCode: " << std::hex << int(opCode)
                  << std::dec << ")" << std::endl;
    }
    void fun(StackFrameRef frame) override {
        frame->pushOperandStack(Value(3)); // 将常量 3 压入操作数栈
    }
};

// iconst_4 指令（将常量 4 压入操作数栈）
class Iconst4Instruction : public instruction {
  public:
    Iconst4Instruction() {
        opCode = 0x07; // 操作码为 0x07 对应 iconst_4
    }
    void print() const override {
        std::cout << "Iconst4Instruction (opCode: " << std::hex << int(opCode)
                  << std::dec << ")" << std::endl;
    }
    void fun(StackFrameRef frame) override {
        frame->pushOperandStack(Value(4)); // 将常量 4 压入操作数栈
    }
};

// iconst_5 指令（将常量 5 压入操作数栈）
class Iconst5Instruction : public instruction {
  public:
    Iconst5Instruction() {
        opCode = 0x08; // 操作码为 0x08 对应 iconst_5
    }
    void print() const override {
        std::cout << "Iconst5Instruction (opCode: " << std::hex << int(opCode)
                  << std::dec << ")" << std::endl;
    }
    void fun(StackFrameRef frame) override {
        frame->pushOperandStack(Value(5)); // 将常量 5 压入操作数栈
    }
};

// bipush 指令（将一个字节常量压入操作数栈）
class BipushInstruction : public instruction {
  public:
    u1 value;
    BipushInstruction(u1 val) : value(val) {
        opCode = 0x10; // 操作码为 0x10 对应 bipush
    }
    void print() const override {
        std::cout << "BipushInstruction (opCode: " << std::hex << int(opCode)
                  << std::dec << ", value: " << int(value) << ")" << std::endl;
    }
    void fun(StackFrameRef frame) override {
        frame->pushOperandStack(Value(int(value))); // 将字节常量压入操作数栈
    }
};

// sipush 指令（将一个短整型常量压入操作数栈）
class SipushInstruction : public instruction {
  public:
    u2 value;
    SipushInstruction(u2 val) : value(val) {
        opCode = 0x11; // 操作码为 0x11 对应 sipush
    }
    void print() const override {
        std::cout << "SipushInstruction (opCode: " << std::hex << int(opCode)
                  << std::dec << ", value: " << int(value) << ")" << std::endl;
    }
    void fun(StackFrameRef frame) override {
        frame->pushOperandStack(Value(int(value))); // 将短整型常量压入操作数栈
    }
};

} // namespace mini
