#include "mysyslog.h"
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdarg.h>

// Прототипы функций для драйверов
int text_driver(const char* msg, LogLevel level, const char* path, LogFormat format);
int json_driver(const char* msg, LogLevel level, const char* path, LogFormat format);

int mysyslog(const char* msg, int level, int driver, int format, const char* path) {
    if (msg == NULL || path == NULL) {
        fprintf(stderr, "Error: Null pointer argument\n");
        return -1;
    }

    // Получаем текущее время
    time_t rawtime;
    struct tm *timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);

    // Преобразуем уровень логирования в строку
    const char *level_str;
    switch (level) {
        case DEBUG:   level_str = "DEBUG";   break;
        case INFO:    level_str = "INFO";    break;
        case WARN:    level_str = "WARN";    break;
        case ERROR:   level_str = "ERROR";   break;
        case CRITICAL: level_str = "CRITICAL"; break;
        default:      level_str = "UNKNOWN"; break;
    }

    // Выбираем драйвер
    if (driver == TEXT_DRIVER) {
        return text_driver(msg, level, path, format);
    } else if (driver == JSON_DRIVER) {
        return json_driver(msg, level, path, format);
    } else {
        fprintf(stderr, "Error: Unknown driver\n");
        return -1;
    }
}

// Реализация text_driver
int text_driver(const char* msg, LogLevel level, const char* path, LogFormat format) {
    FILE *fp = fopen(path, "a");
    if (fp == NULL) {
        perror("Error opening file");
        return -1;
    }
    time_t rawtime;
    struct tm *timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);

    const char *level_str;
    switch (level) {
        case DEBUG:   level_str = "DEBUG";   break;
        case INFO:    level_str = "INFO";    break;
        case WARN:    level_str = "WARN";    break;
        case ERROR:   level_str = "ERROR";   break;
        case CRITICAL: level_str = "CRITICAL"; break;
        default:      level_str = "UNKNOWN"; break;
    }
     if (format == TEXT)
    {
        fprintf(fp, "%ld %s %s %s\n", (long)timeinfo->tm_sec, level_str, "process", msg); //  Предполагаем имя процесса "process"
    }
    else if (format == JSON)
    {
        fprintf(stderr, "Error: Json format not implemented for text driver\n");
        fclose(fp);
        return -1;
    }
    else
    {
        fprintf(stderr, "Error: Unknown format\n");
        fclose(fp);
        return -1;
    }

    fclose(fp);
    return 0;
}

// Реализация json_driver
int json_driver(const char* msg, LogLevel level, const char* path, LogFormat format) {
    FILE *fp = fopen(path, "a");
    if (fp == NULL) {
        perror("Error opening file");
        return -1;
    }
     time_t rawtime;
    struct tm *timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);

    const char *level_str;
    switch (level) {
        case DEBUG:   level_str = "DEBUG";   break;
        case INFO:    level_str = "INFO";    break;
        case WARN:    level_str = "WARN";    break;
        case ERROR:   level_str = "ERROR";   break;
        case CRITICAL: level_str = "CRITICAL"; break;
        default:      level_str = "UNKNOWN"; break;
    }
     if (format == JSON)
    {
         fprintf(fp, "{\"timestamp\":%ld,\"log_level\":\"%s\",\"process\":\"process\",\"message\":\"%s\"}\n", (long)timeinfo->tm_sec, level_str, msg);
    }
    else if (format == TEXT)
    {
         fprintf(stderr, "Error: Text format not implemented for json driver\n");
         fclose(fp);
        return -1;
    }
    else
    {
         fprintf(stderr, "Error: Unknown format\n");
        fclose(fp);
        return -1;
    }
    fclose(fp);
    return 0;
}
