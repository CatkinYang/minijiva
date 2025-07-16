#include "engine/instructions/instruction.hpp"
#include "engine/instructions/iaddIst.hpp"
#include "engine/instructions/iconstIst.hpp"
#include "engine/instructions/iloadIst.hpp"
#include "engine/instructions/istoreIst.hpp"

namespace mini {

instruction::instructionRef instruction::create(u1 opCode,
                                                std::vector<u1> &code) {
    switch (opCode) {
    // 无参数指令
    case 0x03: // iconst_0
        return std::make_unique<Iconst0Instruction>();
    case 0x04: // iconst_1
        return std::make_unique<Iconst1Instruction>();
    case 0x05: // iconst_2
        return std::make_unique<Iconst2Instruction>();
    case 0x06: // iconst_3
        return std::make_unique<Iconst3Instruction>();
    case 0x07: // iconst_4
        return std::make_unique<Iconst4Instruction>();
    case 0x08: // iconst_5
        return std::make_unique<Iconst5Instruction>();
    case 0x02: // iconst_m1
        return std::make_unique<IconstM1Instruction>();

    // 存储局部变量指令
    case 0x36: // istore
        return std::make_unique<IstoreInstruction>(
            code[1]); // 参数：局部变量索引

    case 0x3B: // istore_0
        return std::make_unique<Istore0Instruction>();
    case 0x3C: // istore_1
        return std::make_unique<Istore1Instruction>();
    case 0x3D: // istore_2
        return std::make_unique<Istore2Instruction>();
    case 0x3E: // istore_3
        return std::make_unique<Istore3Instruction>();

    // 加载局部变量指令
    case 0x15: // iload
        return std::make_unique<IloadInstruction>(
            code[1]); // 参数：局部变量索引

    case 0x1F: // iload_1
        return std::make_unique<Iload1Instruction>();
    case 0x20: // iload_2
        return std::make_unique<Iload2Instruction>();
    case 0x21: // iload_3
        return std::make_unique<Iload3Instruction>();

    // 算术运算
    case 0x60: // iadd
        return std::make_unique<IaddInstruction>();

    // 局部变量增量指令
    case 0x84: // iinc
        return std::make_unique<IincInstruction>(
            code[1], code[2]); // 参数：局部变量索引和增量

    // 控制流指令
    case 0xA7: // goto
        return std::make_unique<GotoInstruction>((code[1] << 8) |
                                                 code[2]); // 跳转目标地址

    // 返回指令
    case 0xAC: // ireturn
        return std::make_unique<IreturnInstruction>();

    // 新对象指令
    case 0xBB: // new
        return std::make_unique<NewInstruction>((code[1] << 8) |
                                                code[2]); // 目标类索引

    // 复制栈顶指令
    case 0x59: // dup
        return std::make_unique<DupInstruction>();

    // 调用特殊方法
    case 0xB7: // invokespecial
        return std::make_unique<InvokeSpecialInstruction>(code[1] << 8 |
                                                          code[2]); // 方法索引

    // 调用虚拟方法
    case 0xB6: // invokevirtual
        return std::make_unique<InvokeVirtualInstruction>(code[1] << 8 |
                                                          code[2]); // 方法索引

    // 将短整型常量压栈
    case 0x11: // sipush
        return std::make_unique<SipushInstruction>((code[1] << 8) | code[2]);

    default:
        throw std::runtime_error("Unsupported opCode: " +
                                 std::to_string(opCode));
    }
}

} // namespace mini
