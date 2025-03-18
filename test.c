#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include "mysyslog.h"

int main() {
    mysyslog("Это тестовое сообщение (TEXT) - INFO.", LOG_INFO, TEXT_DRIVER_ID, TEXT_FORMAT, "/tmp/mylog.txt", "test_app");
    mysyslog("Предупреждение (TEXT) - WARNING.", LOG_WARN, TEXT_DRIVER_ID, TEXT_FORMAT, "/tmp/mylog.txt", "test_app");
    mysyslog("Ошибка (TEXT) - ERROR.", LOG_ERROR, TEXT_DRIVER_ID, TEXT_FORMAT, "/tmp/mylog.txt", "test_app");

    mysyslog("Это тестовое сообщение (JSON) - INFO.", LOG_INFO, JSON_DRIVER_ID, JSON_FORMAT, "/tmp/mylog.json", "test_app");
    mysyslog("Предупреждение (JSON) - WARNING.", LOG_WARN, JSON_DRIVER_ID, JSON_FORMAT, "/tmp/mylog.json", "test_app");
    mysyslog("Ошибка (JSON) - ERROR.", LOG_ERROR, JSON_DRIVER_ID, JSON_FORMAT, "/tmp/mylog.json", "test_app");

    printf("Сообщения записаны в файлы /tmp/mylog.txt и /tmp/mylog.json\n");

    return 0;
}
