#include "sudo_guard.h"
#include "util/conf/d_conf.h"
#include "constants.h"
void sudo_keep_watch(){
    if (time_check()){
        system(REMOVE_WHEEL);
    }
    else if (!time_check()){
        system(ADD_WHEEL);
    }
    else{
        log_panic("Sudo guard time check was unclear.");
    }
}