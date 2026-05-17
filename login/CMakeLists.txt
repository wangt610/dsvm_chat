add_library(login_api STATIC
    UserAPI.cpp
    UserAPI.h
)

# 让外部能找到头文件
target_include_directories(login_api PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# 依赖 mysql 模块
target_link_libraries(login_api PUBLIC mysql_lib)