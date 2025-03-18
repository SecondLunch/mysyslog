#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include "mysyslog.h" // Убедись, что путь к этому файлу верный

// Структура для хранения параметров командной строки
typedef struct {
    char *message;
    int level;
    int driver;
    int format;
    char *path;
} ClientOptions;

// Функция для обработки аргументов командной строки с использованием getopt
ClientOptions parse_command_line(int argc, char *argv[]) {
    ClientOptions options = {
        .message = NULL,
        .level = LOG_INFO, // Значение по умолчанию
        .driver = TEXT_DRIVER_ID, // Значение по умолчанию
        .format = TEXT_FORMAT, // Значение по умолчанию
        .path = "/tmp/mylog_client.txt" // Значение по умолчанию
    };

    int opt;
    // Определение опций командной строки
    struct option long_options[] = {
        {"message",  required_argument, 0, 'm'},
        {"level",  required_argument, 0, 'l'},
        {"driver",   required_argument, 0, 'd'},
        {"format",   required_argument, 0, 'f'},
        {"path",     required_argument, 0, 'p'},
        {0, 0, 0, 0} // Обязательно завершать массив опций нулями
    };

    // Цикл обработки аргументов
    while ((opt = getopt_long(argc, argv, "m:l:d:f:p:", long_options, NULL)) != -1) {
        switch (opt) {
            case 'm':
                options.message = optarg;
                break;
            case 'l':
                options.level = atoi(optarg);
                break;
            case 'd':
                options.driver = atoi(optarg);
                break;
            case 'f':
                options.format = atoi(optarg);
                break;
            case 'p':
                options.path = optarg;
                break;
            case '?': // Неизвестная опция или пропущен аргумент
                fprintf(stderr, "Usage: mysyslog-client -m <message> -l <level> -d <driver> -f <format> -p <path>\n");
                exit(EXIT_FAILURE);
            default:
                // Не должно произойти
                abort();
        }
    }

    // Проверка обязательного параметра (message)
    if (options.message == NULL) {
        fprintf(stderr, "Error: Message (-m) is required.\n");
        fprintf(stderr, "Usage: mysyslog-client -m <message> -l <level> -d <driver> -f <format> -p <path>\n");
        exit(EXIT_FAILURE);
    }

    return options;
}

int main(int argc, char *argv[]) {
    // Обработка аргументов командной строки
    ClientOptions options = parse_command_line(argc, argv);

    // Вызов функции mysyslog с полученными параметрами
    mysyslog(options.message, options.level, options.driver, options.format, options.path, "mysyslog-client");

    printf("Log message sent.\n");

    return 0;
}
