#ifndef D_LOG
#define D_LOG
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

void log_panic(char *filename, char *message);
void log_info(char *filename, char *message);
char *get_current_datetime();

#endif