add_library(mysql_lib STATIC
    MySQLManager.cpp
    MySQLManager.h
)

# 让外部能找到头文件
target_include_directories(mysql_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# 链接 MySQL 客户端库（如果是交叉编译，这里要改成 Android 版的 libmysqlclient）
# 先注释掉，Android 端我们后面再专门配置
# target_link_libraries(mysql_lib PUBLIC libmysqlclient)