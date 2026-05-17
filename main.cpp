#include"MySQLManager.h"
int main() {
    MySQLManager& db = MySQLManager::getInstance();
    if (!db.init()) {
        printf("Failed to connect to database\n");
        return -1;
    }
    printf("Connected to database successfully\n");
    return 0;
}