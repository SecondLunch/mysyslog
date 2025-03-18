#ifndef LIBMYSYSLOG_TEXT_H
#define LIBMYSYSLOG_TEXT_H

#include "mysyslog.h" // Подключаем mysyslog.h для LogLevel

int text_driver(const char* msg, int level, const char* path, int format, const char* process);

#endif
