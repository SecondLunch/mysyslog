#ifndef MYSYSLOG_H
#define MYSYSLOG_H

typedef enum {
    DEBUG,
    INFO,
    WARN,
    ERROR,
    CRITICAL
} LogLevel;

// Определи константы для уровней логирования
#define LOG_DEBUG    0
#define LOG_INFO     1
#define LOG_WARN     2
#define LOG_ERROR    3
#define LOG_CRITICAL 4

// Определи типы данных для форматов вывода
typedef enum {
    TEXT,
    JSON
} LogFormat;

// Определи константы для форматов
#define TEXT_FORMAT 0
#define JSON_FORMAT 1

// Определи типы данных для драйверов
typedef enum {
    TEXT_DRIVER,
    JSON_DRIVER
} LogDriver;

// Определи константы для драйверов
#define TEXT_DRIVER_ID 0
#define JSON_DRIVER_ID 1

// Объявление функции mysyslog
int mysyslog(const char* msg, int level, int driver, int format, const char* path, const char* process);

#endif
