#ifndef LIBMYSYSLOG_JSON_H
#define LIBMYSYSLOG_JSON_H

#include "mysyslog.h" // Подключаем mysyslog.h для LogLevel

int json_driver(const char* msg, int level, const char* path, int format, const char* process);

#endif
