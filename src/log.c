#include "../include/log.h"

LogFile create_runtime_session_logfile() {
    time_t now = time(NULL);
    struct tm* local = localtime(&now);
    char file_path[33];
    strftime(file_path, sizeof(file_path), "logs/log_%d_%m_%Y_%H_%M_%S.log", local);
    LogFile log_file = fopen(file_path, "a");
    if (log_file == NULL) {
        perror("Can't create a new log_file file for this run session. Switching to print mode.");
        log_file = stdout;
    }
    return log_file;
}

void gen_logs(LogFile log_file, LogType type, char* format, ...) {
    char log_str[5][8] = {"INFO", "DEBUG", "WARNING", "ERROR", "CRITICAL"};
    fprintf(log_file,"%s: ", log_str[type]);
    // Handle variable arguments
    va_list args;
    va_start(args, format);
    vfprintf(log_file, format, args);
    va_end(args);
    fprintf(log_file, "\n");
    fflush(log_file); // Ensure the log_file entry is immediately written to the file
}