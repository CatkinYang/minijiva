#include "classReader.hpp"
#include "parser.hpp"
#include <filesystem>
#include <fstream>

using namespace mini;
namespace fs = std::filesystem;

int main() {
    std::string testFile =
        "/Users/catkin/workspace/hygon/minijiva/sum/TestCountedLoop2.class";
    auto ps = new parser();
    ps->fileToObject(testFile);
    return 0;
}
