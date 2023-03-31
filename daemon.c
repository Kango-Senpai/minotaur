/*Wrapper libraries for linux syscalls*/
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>
/*Standard libraries*/
#include <stdlib.h>
/*Daemon-specific libraries and modules*/
#include "util/log/d_log.h"
#include "util/conf/d_conf.h"
/*Definition of global variables for the working directory and log and config files.*/
#define WORKING_DIR "/home/henry/minotaur.d"
#define LOG_FILE "minotaur.log"
#define CONF_FILE "minotaur.conf"
int main(void){
    pid_t pid, sid;
    /*Fork off the parent process.*/
    pid = fork();
    if (pid < 0) {
        log_panic(LOG_FILE, "Failed to fork off parent process!");
        exit(EXIT_FAILURE);
    }
    if (pid > 0){
        exit(EXIT_SUCCESS);
    }

    /*Change the file mode mask for total control. Code 0.*/
    umask(0);

    /*Set session id for the child process*/
    sid = setsid();
    if (sid < 0){
        log_panic(LOG_FILE, "Failed to aquire session id for child process!");
        exit(EXIT_FAILURE);
    }

    /*Change the working directory of the daemon*/
    if ((chdir(WORKING_DIR)) < 0){
        log_panic("Failed to change working directory to %s",WORKING_DIR);
        exit(EXIT_FAILURE);
    }
    
    /*Close unused file descriptors.*/
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    /*Daemon code goes here...*/
    char *string_time = malloc(sizeof(char)*6);
    char* string_time2 = malloc(sizeof(char)*6);
    struct tm *start_time = get_start_time(CONF_FILE);
    struct tm *end_time = get_end_time(CONF_FILE);
    strftime(string_time,7,"%H:%M",start_time);
    strftime(string_time2,7,"%H:%M",end_time);
    log_info(LOG_FILE,("%s",string_time));
    log_info(LOG_FILE,("%s",string_time2));

    if (start_time > end_time){
        log_info(LOG_FILE,"Start time is greater.");
    }

    else {
        log_info(LOG_FILE,"End time is greater.");
    }
    free(string_time);
    free(string_time2);


    //TODO compare the times and determine which is earlier.
    /*Exit child process...*/
    exit(EXIT_SUCCESS);
}