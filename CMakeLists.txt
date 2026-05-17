cmake_minimum_required(VERSION 3.10)
project(chat_server)

# C++17 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# MySQL 配置（你电脑的路径）
set(MYSQL_INCLUDE_DIR "C:/Program Files/MySQL/MySQL Server 8.0/include")
set(MYSQL_LIB_DIR     "C:/Program Files/MySQL/MySQL Server 8.0/lib")

# 引入 MySQL 头文件
include_directories(${MYSQL_INCLUDE_DIR})
link_directories(${MYSQL_LIB_DIR})

# 包含 mysql 模块
add_subdirectory(mysql)

# 生成可执行文件
add_executable(chat_server main.cpp)

# 链接数据库模块
target_link_libraries(chat_server PRIVATE mysql_lib)

# Windows 自动复制 libmysql.dll → 永远不再缺库！
if(WIN32)
add_custom_command(TARGET chat_server POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
    "${MYSQL_LIB_DIR}/libmysql.dll"
    $<TARGET_FILE_DIR:chat_server>
)
endif()