#ifndef LOG_H
#define LOG_H

#include <stdio.h>
#include <time.h>
#include <stdarg.h> 

typedef FILE* LogFile;
typedef enum {
    INFO, DEBUG, WARNING, ERROR, CRITICAL
} LogType;

/// @brief Creates a new log file each time the application is ran.
/// @return The pointer to the created file.
extern LogFile create_runtime_session_logfile() __THROW;

/// @brief Makes a log entry in the given created log file.
/// @param log_file The pointer to the created log file.
/// @param type The type of info the log msg has.
/// @param format The format string of the log message.
extern void gen_logs(LogFile log_file, LogType type, char* format, ...);

#endif // LOG_H