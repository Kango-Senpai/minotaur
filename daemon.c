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
#include "constants.h"
#include "sudo_guard.h"

void daemonize(){
    pid_t pid, sid;
    /*Fork off the parent process.*/
    pid = fork();
    if (pid < 0) {
        log_panic("Failed to fork off parent process!");
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
        log_panic("Failed to aquire session id for child process!");
        exit(EXIT_FAILURE);
    }

    /*Change the working directory of the daemon*/
    if ((chdir(WORKING_DIR)) < 0){
        log_panic(("Failed to change working directory to %s",WORKING_DIR));
        exit(EXIT_FAILURE);
    }
    
    /*Close unused file descriptors.*/
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

}

int main(void){
    daemonize();
    /*Daemon code goes here...*/
    int cycles = 1;
    while (cycles > 0){
        cycles--;
        //Execute task subroutines.
        log_info("Attempting to complete tasks...");
        sudo_keep_watch();
        //Sleep 30 seconds...Continue work.
        sleep(30);
    }

    /*Exit child process...*/
    exit(EXIT_SUCCESS);
}