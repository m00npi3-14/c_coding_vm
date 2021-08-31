#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>


int min = INT_MAX;
int max = INT_MIN;

//void year_max(int *point);

struct meas 
{
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int temp;
} m;

int main(int argc, char **argv)
{

    /*if (argc < 2) 
    {
        return -1;
    }
    char *file = argv[1];*/

    FILE *f = fopen("temp.csv", "r");
    if (!f) 
    {
        printf("Error opening file\n");
        return 0;
    }

    int month =0;
    int *p;
    p = &month;

    //scanf("%d", &month);

    int row = 0;
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


        row++;
        void month_min() {
        
            if( m.temp < min && m.month == month) min = m.temp;
        }
        
        //year_max(*p);

        /*if(m.hour==2 && m.day == 1 && m.month == 1)
        {
            printf("Woooow %d\n", m.temp);
        }*/

    }

    printf("counter %d\n", row);

    
    printf("Minimum temp 1: %d\n", min);
    printf("Maximum temp: %d\n", max);

    fclose(f);


    return 0;
}

void year_max(int *point) 
{
    //if( m.temp > max && m.month == p ) max = m.temp;
}
