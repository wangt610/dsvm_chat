#ifndef MYSQL_MANAGER_H
#define MYSQL_MANAGER_H

#include <mysql.h>
#include <string>
#include <memory>
#include <cstdio>
class MySQLManager {
public:
    static MySQLManager& getInstance();
    bool init();
    bool query(const char* sql);
    MYSQL_RES* queryResult(const char* sql);

     // 注册：账号密码存入数据库
    bool RegisterUser(const std::string& name, const std::string& pwd);
    // 登录：查询账号密码是否匹配
    bool LoginCheck(const std::string& name, const std::string& pwd);

    
    MYSQL* getConn();

private:
    MySQLManager();
    ~MySQLManager();
    struct impl;
    std::unique_ptr<impl> pImpl;
};

#endif