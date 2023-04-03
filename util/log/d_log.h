#ifndef D_LOG
#define D_LOG
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "../../constants.h"

void log_panic(char *message);
void log_info(char *message);
void log_debug(char* message);
char *get_datetime();
struct tm *get_datetime_struct();
#endif