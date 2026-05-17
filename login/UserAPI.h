#ifndef USER_API_H
#define USER_API_H

#ifdef __cplusplus
extern "C" {
#endif

// 注册接口：成功返回0，失败返回-1
int user_register(const char* username, const char* password);

// 登录接口：成功返回0，失败返回-1
int user_login(const char* username, const char* password);

#ifdef __cplusplus
}
#endif

#endif