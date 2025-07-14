#pragma once
#include <cstdint>
namespace mini {
// 类文件 类
//
// 需要有一个parser将 class文件  转换成 classFile类
// 1. 魔数
// 2. 次版本号
// 3. 主版本号
// 4. 常量池入口
class classfile {
  public:
    // 构造函数
  private:
    uint32_t magicNumber_;   // 4字节 魔数
    uint16_t subVersion_;    // 2字节 次版本号
    uint16_t majorVersion_;  // 2字节 主版本号
    uint16_t constPoolNum_;  // 2字节 常量池大小
    ;                        // 常量池，需要依据常量池大小进行初始化？
    uint16_t accessFlags_;   // 2字节 访问标识
    uint16_t classRef_;      // 2字节，类索引
    uint16_t superClassRef_; // 2字节 父类索引
    uint16_t interfaceNum_;  // 2字节 接口索引个数
    uint16_t filedNun_;      // 2字节 字段个数
    uint16_t methodNum_;     // 2字节 方法个数
    uint16_t attrNum_;       // 2字节 属性个数
};
} // namespace mini
