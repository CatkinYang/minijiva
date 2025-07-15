#pragma once
#include "marco.hpp"
#include <filesystem>
#include <fstream>
namespace mini {
// 打开文件，然后开始读取二进制文件
class classReader {
  public:
    explicit classReader(std::ifstream &stream) : ifs(stream) {}

    u1 readU1() { return static_cast<u1>(ifs.get()); }

    u2 readU2() {
        u1 b1 = readU1();
        u1 b2 = readU1();
        return (b1 << 8) | b2;
    }

    u4 readU4() {
        u1 b1 = readU1();
        u1 b2 = readU1();
        u1 b3 = readU1();
        u1 b4 = readU1();
        return (b1 << 24) | (b2 << 16) | (b3 << 8) | b4;
    }

    void skip(size_t n) { ifs.ignore(n); }

  private:
    std::ifstream &ifs;
};
} // namespace mini
