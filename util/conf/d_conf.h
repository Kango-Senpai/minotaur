#ifndef D_CONF
#define D_CONF

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "../log/d_log.h"
#include "../../constants.h"
//char *fgets(char *line, int maxline, FILE *fp)
//TODO use strptime to clean up functions...
struct tm *get_start_time();
struct tm *get_end_time();
_Bool time_check();
#endif