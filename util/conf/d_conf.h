#ifndef D_CONF
#define D_CONF

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../log/d_log.h"
#define DUMMY_CONF "minotaur.conf.dummy"
//char *fgets(char *line, int maxline, FILE *fp)
struct tm *get_start_time(char *filename);
struct tm *get_end_time(char *filename);
#endif