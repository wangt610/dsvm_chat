#include "UserAPI.h"
#include "mysql/MySQLManager.h"
#include <cstdio>

int user_register(const char* username, const char* password)
{
    if (!username || !password) {
        printf("❌ 参数错误\n");
        return -1;
    }

    MySQLManager& db = MySQLManager::getInstance();
    if (db.RegisterUser(username, password)) {
        return 0; // 注册成功
    } else {
        return -1; // 注册失败
    }
}

int user_login(const char* username, const char* password)
{
    if (!username || !password) {
        printf("❌ 参数错误\n");
        return -1;
    }

    MySQLManager& db = MySQLManager::getInstance();
    if (db.LoginCheck(username, password)) {
        return 0; // 登录成功
    } else {
        return -1; // 登录失败
    }
}