#pragma once
#include "engine/stack.hpp"
#include "engine/value.hpp"
#include "instruction.hpp"
#include "marco.hpp"
namespace mini {

// istore 指令（存储局部变量）
class IstoreInstruction : public instruction {
  public:
    u1 index;
    IstoreInstruction(u1 idx) : index(idx) {
        opCode = 0x36; // 操作码为 0x36 对应 istore
    }
    void print() const override {
        std::cout << "IstoreInstruction (opCode: " << std::hex << int(opCode)
                  << std::dec << ", index: " << int(index) << ")" << std::endl;
    }
    void fun(StackFrameRef frame) override {
        Value value = frame->popOperandStack(); // 从栈弹出值
        frame->setLocalVar(index, value);       // 存储到局部变量表
    }
};

// istore_0 指令（将栈顶的值存储到局部变量 1）
class Istore0Instruction : public instruction {
  public:
    Istore0Instruction() {
        opCode = 0x3B; // 操作码为 0x3B 对应 istore_0
    }

    void print() const override {
        std::cout << "Istore0Instruction (opCode: " << std::hex << int(opCode)
                  << std::dec << ")" << std::endl;
    }

    void fun(StackFrameRef frame) override {
        Value value = frame->popOperandStack(); // 从操作数栈弹出一个值
        frame->setLocalVar(0, value); // 将值存储到局部变量表的第 0 个位置
    }
};

// istore_1 指令（将栈顶的值存储到局部变量 1）
class Istore1Instruction : public instruction {
  public:
    Istore1Instruction() {
        opCode = 0x3C; // 操作码为 0x3C 对应 istore_1
    }

    void print() const override {
        std::cout << "Istore1Instruction (opCode: " << std::hex << int(opCode)
                  << std::dec << ")" << std::endl;
    }

    void fun(StackFrameRef frame) override {
        Value value = frame->popOperandStack(); // 从操作数栈弹出一个值
        frame->setLocalVar(1, value); // 将值存储到局部变量表的第 1 个位置
    }
};

// istore_2 指令
class Istore2Instruction : public instruction {
  public:
    Istore2Instruction() {
        opCode = 0x3D; // 操作码为 0x3D 对应 istore_2
    }

    void print() const override {
        std::cout << "Istore2Instruction (opCode: " << std::hex << int(opCode)
                  << std::dec << ")" << std::endl;
    }

    void fun(StackFrameRef frame) override {
        Value value = frame->popOperandStack(); // 从操作数栈弹出一个值
        frame->setLocalVar(2, value); // 将值存储到局部变量表的第 2 个位置
    }
};

// istore_3 指令
class Istore3Instruction : public instruction {
  public:
    Istore3Instruction() {
        opCode = 0x3E; // 操作码为 0x3E 对应 istore_3
    }
    void print() const override {
        std::cout << "Istore3Instruction (opCode: " << std::hex << int(opCode)
                  << std::dec << ")" << std::endl;
    }
    void fun(StackFrameRef frame) override {
        Value value = frame->popOperandStack(); // 从操作数栈弹出一个值
        frame->setLocalVar(3, value); // 将值存储到局部变量表的第 3 个位置
    }
};

} // namespace mini
