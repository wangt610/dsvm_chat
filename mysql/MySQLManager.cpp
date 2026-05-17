#include "MySQLManager.h"

MySQLManager::MySQLManager() : conn(nullptr) {}
MySQLManager::~MySQLManager() {
    if (conn) mysql_close(conn);
}

MySQLManager& MySQLManager::getInstance() {
    static MySQLManager instance;
    return instance;
}

bool MySQLManager::init() {
    conn = mysql_init(nullptr);
    if (!conn) return false;

    // 你自己改MySQL地址/账号/密码/库名
    return mysql_real_connect(conn,
        "localhost", "root", "20050610", "chat_system", 3306, nullptr, 0);
}

bool MySQLManager::query(const char* sql) {
    return mysql_query(conn, sql) == 0;
}

MYSQL_RES* MySQLManager::queryResult(const char* sql) {
    if (mysql_query(conn, sql)) return nullptr;
    return mysql_store_result(conn);
}

MYSQL* MySQLManager::getConn() {
    return conn;
}

// 注册用户
bool MySQLManager::RegisterUser(const std::string& name, const std::string& pwd)
{
    char sql[512] = {0};
    sprintf(sql, "INSERT INTO users(username,password) VALUES('%s','%s')", name.c_str(), pwd.c_str());

    if (mysql_query(conn, sql) != 0)
    {
        printf("注册失败：%s\n", mysql_error(conn));
        return false;
    }
    printf("注册成功！\n");
    return true;
}

// 登录校验
bool MySQLManager::LoginCheck(const std::string& name, const std::string& pwd)
{
    char sql[512] = {0};
    sprintf(sql, "SELECT * FROM users WHERE username='%s' AND password='%s'", name.c_str(), pwd.c_str());

    if (mysql_query(conn, sql) != 0)
    {
        printf("查询失败：%s\n", mysql_error(conn));
        return false;
    }

    MYSQL_RES* res = mysql_store_result(conn);
    if (!res)
    {
        printf("无查询结果\n");
        return false;
    }

    int row = mysql_num_rows(res);
    mysql_free_result(res);

    if (row > 0)
    {
        printf("登录验证通过\n");
        return true;
    }
    else
    {
        printf("账号或密码错误\n");
        return false;
    }
}