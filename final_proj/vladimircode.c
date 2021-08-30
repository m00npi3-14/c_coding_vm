#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>


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
    printf("test1\n");

    /*if (argc < 2) 
    {
        printf("some problem\n");
        return -1;
    }
    char *file = argv[1];*/

    FILE *f = fopen("temp.csv", "r");
    if (!f) 
    {
        printf("Error opening file\n");
        return 0;
    }

    printf("test\n");
    
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

        /*if(m.hour==2 && m.day == 1 && m.month == 1)
        {
            printf("Woooow %d\n", m.temp);
        }*/

        printf("ysdhd  ighdsi  %d\n", m[2].temp);

        int min = 0;

        while(m.month==12)
        {
            if(m.temp < min)
            {
                min = m.temp;
                printf("Min in this year = %d   %d\n", min, m.minute);
            }
        }

        //int min = 0;
        //int *p = NULL;
        //p = &min;
        
        /*if(m.temp < min)
        {
            min = m.temp;
            printf("Min in this year = %d   %d\n", min, m.minute);
        }*/
        
    }
    printf("ukigiogb\n");
    int i = 0;


    printf("is year %d\n", m.year);
    
    
    fclose(f);


    return 0;
}
