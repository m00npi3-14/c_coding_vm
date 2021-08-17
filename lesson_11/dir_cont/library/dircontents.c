#include "dircontents.h"

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

void print_dir_contents(const char *strdir) 
{
    DIR *dir;
    struct dirent *entry;
    dir = opendir(strdir);
    if (dir)
    {
        while(entry = readdir(dir))
        {
            
            if(entry->d_name[0] == '.') {
                continue;
            }
            else {
                printf("file__ %s\n", entry->d_name);
            }

            
        }
    }
}