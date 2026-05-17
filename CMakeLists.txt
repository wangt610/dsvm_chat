cmake_minimum_required(VERSION 3.10)
project(DSVM_CHAT CXX)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 1. 配置 MySQL 头文件和库路径（根据你的实际路径修改）
set(MYSQL_INCLUDE_DIR "C:/Program Files/MySQL/MySQL Server 8.0/include")
set(MYSQL_LIB_DIR     "C:/Program Files/MySQL/MySQL Server 8.0/lib")
set(MYSQL_LIBRARY     "libmysql.lib")

# 2. 添加头文件目录
include_directories(${MYSQL_INCLUDE_DIR})

# 3. 添加可执行文件
add_executable(chat_server
    main.cpp
    MySQLManager.cpp
)

# 4. 链接 MySQL 库
target_link_libraries(chat_server
    ${MYSQL_LIB_DIR}/${MYSQL_LIBRARY}
)