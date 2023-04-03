#include "d_log.h"

void log_panic(char *message){
    FILE *logfile = fopen(LOG_FILE, "a+");
    if (!logfile) {
        return;
    }
    fprintf(logfile,"[PANIC] \"%s\"\n", message);
    fclose(logfile);
}

void log_info(char *message){
    FILE *logfile;
    logfile = fopen(LOG_FILE, "a+");
    if (!logfile) {
        return;
    }
    fprintf(logfile, "[INFO] %s \"%s\"\n", get_datetime() , message);
    fclose(logfile);
}

void log_debug(char *message){
    FILE *logfile;

    logfile = fopen(LOG_FILE, "a+");
    if (!logfile) {
        return;
    }
    fprintf(logfile, "[DEBUG] %s \"%s\"\n", get_datetime() , message);
    fclose(logfile);
}

struct tm *get_datetime_struct() {
    time_t unix_time = time(NULL);
    if (unix_time == -1){
        log_panic("Aquisition of raw unix time failed!");
        return NULL;
    }
    struct tm *local_time = localtime(&unix_time);
    if (local_time == NULL){
        log_panic("Failed to convert unix time into local time!");
        return NULL;
    }
    return local_time;
}

char *get_datetime() {
    char *time_string = malloc(sizeof(char)*20);
    strftime(time_string,20,("%a %b %d %H:%M:%S"),get_datetime_struct());
    return time_string;
}