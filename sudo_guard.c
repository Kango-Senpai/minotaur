#include "unistd.h"
#include "sudo_guard.h"
#include "util/conf/d_conf.h"
#include "constants.h"
void sudo_keep_watch(){
    if (time_check()){
        log_info("System clock is within the configured range. Removing the target from group 'wheel'.");
        system(REMOVE_WHEEL);
    }
    else if (!time_check()){
        log_info("System clock is outside the configured range. Restoring access to group 'wheel'.");
        system(ADD_WHEEL);
    }
    else{
        log_panic("Sudo guard time check was unclear. Defaulting to removal from wheel.");
        system(REMOVE_WHEEL);
    }
}