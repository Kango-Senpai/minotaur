#include "d_log.h"

void log_panic(char *filename, char *message){
    FILE *logfile = fopen(filename, "a+");
    if (!logfile) {
        return;
    }
    fprintf(logfile,"[PANIC] \"%s\"", message);
    fclose(logfile);
}

void log_info(char *filename, char *message){
    FILE *logfile;

    logfile = fopen(filename, "a+");
    if (!logfile) {
        return;
    }
    fprintf(logfile, "[INFO] %s \"%s\"\n", get_current_datetime() , message);
    fclose(logfile);
}


char *get_current_datetime() {
    time_t unix_time = time(NULL);
    if (unix_time == -1){
        log_panic("daemon.log","Aquisition of raw unix time failed!");
        return NULL;
    }
    struct tm *local_time = localtime(&unix_time);
    if (local_time == NULL){
        log_panic("daemon.log","Failed to convert unix time into local time!");
        return NULL;
    }
    char *time_string = malloc(sizeof(char)*20);
    strftime(time_string,20,("%a %b %d %H:%M:%S"),local_time);
    return time_string;
}

