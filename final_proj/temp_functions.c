#include "temp_functions.h"

#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>

void min_year(int* pointer, int temperature)
{
    if(temperature < *pointer)
    {
        *pointer = temperature;
    }
}

void max_year(int* pointer, int temperature)
{
    if(temperature > *pointer)
    {
        *pointer = temperature;
    }
}

void minimum_month(int* pointer, int temperature)
{
    if(temperature < *pointer)
    {
        *pointer = temperature;
    }
}

void mean_month(int* ctr_pointer, int* sum_pointer, int temperature)
{
    *sum_pointer = *sum_pointer + temperature;
    *ctr_pointer += 1;
}