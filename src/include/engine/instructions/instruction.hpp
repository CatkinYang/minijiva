#pragma once
#include "engine/stack.hpp"
#include "engine/value.hpp"
#include "marco.hpp"
namespace mini {

// 指令基类
// 后面拿模版写不同的指令类型 ?
// 每一个指令都是 一个字节长度的
class instruction {
  public:
    using instructionRef = std::unique_ptr<instruction>;
    u1 opCode;
    std::vector<u1> parameters;
    // 打印指令信息
    virtual void print() const = 0;
    // 指令的具体功能
    virtual void fun(StackFrameRef stackframe) = 0;
    virtual ~instruction() = default;
    // 根据不同的opCode创建不同的指令对象进行操作？
    static instructionRef create(u1 opCode, std::vector<u1> &code);
};

// goto 指令（无条件跳转）
class GotoInstruction : public instruction {
  public:
    u2 target;
    GotoInstruction(u2 tgt) : target(tgt) {
        opCode = 0xA7; // 操作码为 0xA7 对应 goto
    }
    void print() const override {
        std::cout << "GotoInstruction (opCode: " << std::hex << int(opCode)
                  << std::dec << ", target: " << target << ")" << std::endl;
    }
    void fun(StackFrameRef frame) override {
        // 执行跳转，模拟跳转到目标地址
        std::cout << "Jumping to " << target << std::endl;
    }
};

// ireturn 指令（返回操作数栈中的值）
class IreturnInstruction : public instruction {
  public:
    IreturnInstruction() {
        opCode = 0xAC; // 操作码为 0xAC 对应 ireturn
    }
    void print() const override {
        std::cout << "IreturnInstruction (opCode: " << std::hex << int(opCode)
                  << std::dec << ")" << std::endl;
    }
    void fun(StackFrameRef frame) override {
        Value returnValue = frame->popOperandStack(); // 弹出返回值
        std::cout << "Returning value: " << returnValue.toString() << std::endl;
        // 模拟方法的返回操作
    }
};

// iinc 指令（局部变量加法）
class IincInstruction : public instruction {
  public:
    u1 index;     // 局部变量索引
    u1 increment; // 增量值

    IincInstruction(u1 idx, u1 inc) : index(idx), increment(inc) {
        opCode = 0x84; // 操作码为 0x84 对应 iinc
    }
    void print() const override {
        std::cout << "IincInstruction (opCode: " << std::hex << int(opCode)
                  << std::dec << ", index: " << int(index)
                  << ", increment: " << int(increment) << ")" << std::endl;
    }

    void fun(StackFrameRef frame) override {
        Value value = frame->getLocalVar(index); // 获取局部变量
        if (value.is(ValueType::INT)) {
            int result = value.get<int>() + increment;
            frame->setLocalVar(index, Value(result)); // 存回局部变量表
        } else {
            throw std::runtime_error("Invalid type for iinc operation");
        }
    }
};
// new 指令（创建对象）
class NewInstruction : public instruction {
  public:
    u2 classIndex; // 常量池索引，指向类名

    NewInstruction(u2 idx) : classIndex(idx) {
        opCode = 0xBB; // 操作码为 0xBB 对应 new
    }
    void print() const override {
        std::cout << "NewInstruction (opCode: " << std::hex << int(opCode)
                  << std::dec << ", classIndex: " << classIndex << ")"
                  << std::endl;
    }

    void fun(StackFrameRef frame) override {
        // 这里模拟创建新对象操作
        // 通过常量池索引查找类名，创建对象并将其压入操作数栈
    }
};
// dup 指令（复制栈顶元素）
class DupInstruction : public instruction {
  public:
    DupInstruction() {
        opCode = 0x59; // 操作码为 0x59 对应 dup
    }

    void print() const override {
        std::cout << "DupInstruction (opCode: " << std::hex << int(opCode)
                  << std::dec << ")" << std::endl;
    }

    void fun(StackFrameRef frame) override {
        Value top = frame->topOperandStack(); // 获取栈顶的值
        frame->pushOperandStack(top);         // 将栈顶元素压入操作数栈（复制）
    }
};

class InvokeSpecialInstruction : public instruction {
  public:
    u2 methodIndex; // 方法索引（指向常量池中的方法）

    InvokeSpecialInstruction(u2 idx) : methodIndex(idx) {
        opCode = 0xB7; // 操作码为 0xB7 对应 invokespecial
    }

    void print() const override {
        std::cout << "InvokeSpecialInstruction (opCode: " << std::hex
                  << int(opCode) << std::dec << ", methodIndex: " << methodIndex
                  << ")" << std::endl;
    }

    void fun(StackFrameRef frame) override {}
};

// invokevirtual 指令（调用虚拟方法）
class InvokeVirtualInstruction : public instruction {
  public:
    u2 methodIndex; // 方法索引（指向常量池中的方法）

    InvokeVirtualInstruction(u2 idx) : methodIndex(idx) {
        opCode = 0xB6; // 操作码为 0xB6 对应 invokevirtual
    }

    void print() const override {
        std::cout << "InvokeVirtualInstruction (opCode: " << std::hex
                  << int(opCode) << std::dec << ", methodIndex: " << methodIndex
                  << ")" << std::endl;
    }

    void fun(StackFrameRef frame) override {}
};

} // namespace mini
