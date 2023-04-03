#ifndef D_CONF
#define D_CONF

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "../log/d_log.h"

//char *fgets(char *line, int maxline, FILE *fp)
//TODO use strptime to clean up functions...
struct tm *get_start_time(char *filename);
struct tm *get_end_time(char *filename);
_Bool time_check();
#endif