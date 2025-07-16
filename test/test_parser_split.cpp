#include "classReader.hpp"
#include "parser.hpp"
#include <filesystem>
#include <fstream>

using namespace mini;
namespace fs = std::filesystem;

int main() {
    std::string testFile =
        "/Users/catkin/workspace/hygon/minijiva/split/Foo.class";
    auto ps = new parser();
    ps->fileToObject(testFile);
    return 0;
}
