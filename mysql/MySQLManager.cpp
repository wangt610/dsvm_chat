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
        "localhost", "root", "123456", "chatdb", 3306, nullptr, 0);
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