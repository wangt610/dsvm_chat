#ifndef MYSQL_MANAGER_H
#define MYSQL_MANAGER_H

#include <mysql/mysql.h>
#include <string>

class MySQLManager {
public:
    static MySQLManager& getInstance();
    bool init();
    bool query(const char* sql);
    MYSQL_RES* queryResult(const char* sql);
    MYSQL* getConn();

private:
    MySQLManager();
    ~MySQLManager();
    MYSQL* conn;
};

#endif