#include <stdio.h>
#include <time.h>
#include <string.h>
#include "libmysyslog_json.h"

int json_driver(const char* msg, int level, const char* path, int format, const char* process) {
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
         fprintf(fp, "{\"timestamp\":%ld,\"log_level\":\"%s\",\"process\":\"%s\",\"message\":\"%s\"}\n", (long)timeinfo->tm_sec, level_str, process, msg);
    }
    else
    {
         fprintf(stderr, "Error: Wrong format passed\n");
            fclose(fp);
            return -1;
    }

    fclose(fp);
    return 0;
}
