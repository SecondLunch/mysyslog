#ifndef MYSYSLOG_H
#define MYSYSLOG_H

typedef enum {
    DEBUG,
    INFO,
    WARN,
    ERROR,
    CRITICAL
} LogLevel;

// Определи константы для уровней (например, для использования в client)
#define DEBUG   0
#define INFO    1
#define WARN    2
#define ERROR   3
#define CRITICAL 4
// Определи типы данных для форматов вывода
typedef enum {
    TEXT,
    JSON
} LogFormat;
// Определи константы для форматов
#define TEXT 0
#define JSON 1
// Определи типы данных для драйверов
typedef enum {
    TEXT_DRIVER,
    JSON_DRIVER
} LogDriver;
// Определи константы для драйверов
#define TEXT_DRIVER 0
#define JSON_DRIVER 1
// Объявление функции mysyslog
int mysyslog(const char* msg, int level, int driver, int format, const char* path);

#endif
