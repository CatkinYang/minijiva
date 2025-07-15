#include "classReader.hpp"
#include "parser.hpp"
#include <filesystem>
#include <fstream>
#include <gtest/gtest.h>

using namespace mini;
namespace fs = std::filesystem;

class classReaderTest : public ::testing::Test {
  protected:
    std::string testFilePath = "test_classfile.bin";

    void SetUp() override {
        // 写入 4 字节：0x12, 0x34, 0x56, 0x78
        std::ofstream ofs(testFilePath, std::ios::binary);
        u1 data[] = {0x12, 0x34, 0x56, 0x78};
        ofs.write(reinterpret_cast<char *>(data), sizeof(data));
        ofs.close();
    }

    void TearDown() override { fs::remove(testFilePath); }
};

TEST_F(classReaderTest, ReadBytesCorrectly) {
    std::ifstream ifs(testFilePath, std::ios::binary);
    ASSERT_TRUE(ifs.is_open());

    classReader reader(ifs);

    EXPECT_EQ(reader.readU1(), 0x12);
    EXPECT_EQ(reader.readU2(), 0x3456); // 0x34 << 8 | 0x56
    EXPECT_EQ(reader.readU1(), 0x78);   // 剩余最后一个字节

    ifs.close();
}

TEST(ParserTest, CheckOutputMessage) {
    std::string testFile =
        "/Users/catkin/workspace/hygon/minijiva/sum/TestCountedLoop2.class";

    // 捕获标准输出
    testing::internal::CaptureStdout();
    auto cf = parser::fileToObject(testFile);
    std::string output = testing::internal::GetCapturedStdout();

    // 判断输出中是否包含我们想要的信息
    EXPECT_NE(output.find("valid class file format"), std::string::npos);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
