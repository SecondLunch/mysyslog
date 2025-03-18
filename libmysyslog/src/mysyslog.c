#include "mysyslog.h"
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdarg.h>
#include "libmysyslog_text.h"
#include "libmysyslog_json.h"

int mysyslog(const char* msg, int level, int driver, int format, const char* path, const char* process) {
    if (msg == NULL || path == NULL || process == NULL) {
        fprintf(stderr, "Error: Null pointer argument\n");
        return -1;
    }
    if (driver == TEXT_DRIVER) {
        return text_driver(msg, level, path, format, process);
    } else if (driver == JSON_DRIVER) {
        return json_driver(msg, level, path, format, process);
    } else {
        fprintf(stderr, "Error: Unknown driver\n");
        return -1;
    }
}
