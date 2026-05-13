#include "chat_version.h"
#include <cstdio>

// 从 CMake 注入的宏读取版本
std::string get_chat_version()
{
    char buf[32];
    sprintf(buf, "%d.%d.%d", VER_MAJOR, VER_MINOR, VER_PATCH);
    return std::string(buf);
}