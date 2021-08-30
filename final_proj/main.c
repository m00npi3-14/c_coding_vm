#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>

//int mean_month_tempr(*array);

int main(int argc, char **argv)
{
    int arr[3][6] = {
        {2021, 1, 1, 0, 0, -6},
        {2021, 1, 1, 1, 1, 12},
        {2021, 1, 2, 1, 56, 22}
    };

    int k, j, i;


    for (k=0; k<3; k++)
    {
        for(j=0; j<6; j++)
        {
            //printf("mean temp in month %d is %d", arr[])
            printf(" %d", arr[k][j]);
        }printf("\n");
    } 
    
    int a = 0;
    for (i=0; i<3; i++)
    {
        a += arr[i][5];
        
    } printf(" %d\n", a);

}