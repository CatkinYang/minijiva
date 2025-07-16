#pragma once
#include "constant/cp_info.hpp"
#include "marco.hpp"
#include "value.hpp"
#include "vector"
#include <cstddef>
#include <memory>
#include <stack>
namespace mini {

// 局部变量表
class LocalVarTable {
  public:
    std::vector<Value> table;
    LocalVarTable(size_t size) : table(size) {}
    Value &get(size_t index) {
        if (index >= table.size())
            throw std::out_of_range("Index out of range in LocalVariableTable");
        return table[index];
    }
    void set(size_t index, const Value &value) {
        if (index >= table.size())
            throw std::out_of_range("Index out of range in LocalVariableTable");
        table[index] = value;
    }
};

// 栈帧
class StackFrame {
  public:
    StackFrame() = default;

    std::unique_ptr<LocalVarTable> localVarTable; // 局部变量表
    std::stack<Value> OptNumStack;                // 操作数栈
    cp_info *ref;                                 // 指向常量池的引用

    // 获取局部变量
    Value &getLocalVar(size_t index) { return localVarTable->get(index); }
    // 设置局部变量
    void setLocalVar(size_t index, const Value &value) {
        localVarTable->set(index, value);
    }

    // 压栈操作数栈
    void pushOperandStack(const Value &value) { OptNumStack.push(value); }
    // 弹栈操作数栈
    Value popOperandStack() {
        if (OptNumStack.empty()) {
            throw std::runtime_error("Operand stack is empty.");
        }
        Value value = OptNumStack.top();
        OptNumStack.pop();
        return value;
    }

    Value &topOperandStack() {
        if (OptNumStack.empty()) {
            throw std::runtime_error("Operand stack is empty.");
        }
        return OptNumStack.top();
    }

    cp_info *getConstantPoolRef() const { return ref; }
    void setConstantPoolRef(cp_info *refPtr) { ref = refPtr; }
};

using StackFrameRef = std::shared_ptr<StackFrame>;
// 运行时栈,engine
class Stack {
  private:
    std::stack<StackFrameRef> frames;

  public:
    // 压入新的栈帧
    void pushFrame(const StackFrameRef &frame) { frames.push(frame); }
    // 弹出栈帧
    StackFrameRef popFrame() {
        if (frames.empty()) {
            throw std::runtime_error("Stack is empty, cannot pop frame.");
        }
        StackFrameRef frame = frames.top(); // 获取栈顶栈帧的引用
        frames.pop();                       // 弹出栈顶栈帧
        return frame;
    }

    // 获取栈顶栈帧（返回栈顶栈帧的引用）
    StackFrameRef topFrame() {
        if (frames.empty()) {
            throw std::runtime_error(
                "Stack is empty, cannot access top frame.");
        }
        return frames.top(); // 返回栈顶栈帧的共享指针
    }

    // 获取栈顶栈帧（常量引用）
    const StackFrameRef topFrame() const {
        if (frames.empty()) {
            throw std::runtime_error(
                "Stack is empty, cannot access top frame.");
        }
        return frames.top(); // 返回栈顶栈帧的共享指针
    }

    // 检查栈是否为空
    bool isEmpty() const { return frames.empty(); }
    // 获取栈的大小
    auto size() const -> size_t { return frames.size(); }
};
using StackRef = std::shared_ptr<Stack>;

} // namespace mini
