#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>

#include "temp_functions.h"

extern char *optarg;
extern int optind, opterr, optopt;

void help(const char *appname);
void print_month_stats(int numofmonth, int* p_minimum, int* mean_m);

int main(int argc, char **argv)
{
    int ret;
    char *filename;
    int month_num = 0;

    int mins_in_y = 0; //минут в году

    int ctr = 0; //минут в месяце
    int *p_ctr = &ctr;

    int sum_temps_in_month = 0; //сумма температур в заданном месяце
    int *p_sum_m = &sum_temps_in_month;

    int minimum = 0;
    int *p_min = &minimum;

    int maximum = 0;
    int *p_max = NULL;
    p_max = &maximum;

    int min_month = 0;
    int *p_min_month = &min_month;

    int mean = 0;
    int *p_mean = &mean;

    if (argc == 1) {
        help(argv[0]);
        return 0;
    }

    while ((ret = getopt(argc, argv, "hf:m:")) != -1)
    {
        switch(ret) {
            case 'h' : {
                help(argv[0]);
                return 0;
            }

            case 'f' : {
                filename = optarg;
                break;
            }

            case 'm' : {
                month_num = atoi(optarg);
                print_month_stats(month_num, p_min_month, p_mean);
                break;
            }
        }
    }

    FILE *f = fopen(filename, "r");
    if (!f) 
    {
        printf("Error opening file\n");
        return 0;
    }


    while (!feof(f)) 
    {
        struct meas m;

        int scanfret = fscanf(f, "%d;%d;%d;%d;%d;%d",
                &m.year,
                &m.month,
                &m.day,
                &m.hour,
                &m.minute,
                &m.temp);
        

        mins_in_y++;

        min_year(p_min, m.temp);
        max_year(p_max, m.temp);

        if(m.month == month_num)
        {
            minimum_month(p_min_month, m.temp);
            mean_month(p_ctr, p_sum_m, m.temp);
        }
        
    }

    mean = *p_sum_m / *p_ctr;

    printf("Min in year: %d\n", *p_min);
    printf("Max in year: %d\n", *p_max);

    //printf("Rows in csv file:  %d\n", row);
    


    fclose(f);


    return 0;
}

void help(const char *appname)
{
    char text_to_print[1000] = "************    HELP MESSAGE    ************\n"
                                "!!! This program requieres -f<filename.csv> argument. (like this: ./main -f temp.csv)\n"
                                "If you only want to see statistics on one month, also put -m<month's number>. (1 is for Jan, 2-Feb and so on)\n"
                                "If you you want to see this help message again, put a -h argument).\n";
    printf("%s", text_to_print);
    /*If you only want to see statistics on one month, put -m<month's number>.\n
    If you you want to see this help message again, put a -h argument);*/

    printf("You are in %s\n", appname);
}

void print_month_stats(int numofmonth, int* p_minimum, int* mean_m)
{
    printf("Min in month %d: %d\n", numofmonth,*p_minimum);
    printf("Mean in month: %d\n", *mean_m);
}


