#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>

#include "temp_functions.h"

int main(int argc, char **argv)
{
    int month_num=0;
    scanf("%d", &month_num);
    int *p_month_num = &month_num;

    FILE *f = fopen("temp.csv", "r");
    if (!f) 
    {
        printf("Error opening file\n");
        return 0;
    }

    int row = 0;

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
        

        row++; //считаем кол-во строк в файле

        min_year(p_min, m.temp);
        max_year(p_max, m.temp);

        if(m.month == *p_month_num)
        {

            minimum_month(p_min_month, m.temp);
            mean_month(p_ctr, p_sum_m, m.temp);
        }
    } 
        
    int mean = *p_sum_m / *p_ctr;


    printf("Min in year: %d\n", *p_min);
    printf("Max in year: %d\n", *p_max);

    printf("Min in month %d: %d\n", *p_month_num,*p_min_month);

    printf("Rows in csv file:  %d\n", row);

    printf("Mean in month: %d\n", mean);
    


    fclose(f);


    return 0;
}



