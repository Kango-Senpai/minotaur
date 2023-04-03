#include "d_conf.h"
struct tm *get_start_time(char *filename){
    struct tm *start_time = malloc(sizeof(struct tm));
    FILE *conf_file = fopen(filename,"r");
    if (conf_file == NULL){
        log_panic("minotaur.log","Failed to open config file.");
        return start_time;
    }
    char *first_line = malloc(sizeof(char)*13);
    fgets(first_line, 13, conf_file);

    start_time->tm_hour = ((first_line[0] - '0')*10) + (first_line[1] - '0');
    start_time->tm_min = ((first_line[3] - '0')*10) + (first_line[4] - '0');

    free(first_line);
    fclose(conf_file);
    return start_time;
}

struct tm *get_end_time(char *filename) {
    struct tm *end_time = malloc(sizeof(struct tm));
    FILE *conf_file = fopen(filename,"r");
    if (conf_file == NULL){
        log_panic("minotaur.log","Failed to open config file.");
        return end_time;
    }
    char *first_line = malloc(sizeof(char)*13);
    fgets(first_line, 13, conf_file);

    end_time->tm_hour = ((first_line[6] - '0')*10) + (first_line[7] - '0');
    end_time->tm_min = ((first_line[9] - '0')*10) + (first_line[10] - '0');
    
    free(first_line);
    fclose(conf_file);
    return end_time;
}

bool time_check(){
    struct tm *start_time = get_start_time("minotaur.conf");
    struct tm *end_time = get_end_time("minotaur.conf");
    struct tm *current_time = get_datetime_struct();

    if (current_time->tm_hour >= start_time->tm_hour && current_time->tm_hour <= end_time->tm_hour){
        if (current_time->tm_hour == start_time->tm_hour){
            if(current_time->tm_min >= start_time-> tm_min){
                return 1;
            }
        }
        else if (current_time->tm_hour == end_time->tm_hour){
            if(current_time->tm_min < end_time->tm_min){
                return 1;
            }
        }
        else{
            return 1;
        }
    }
    return 0;
}