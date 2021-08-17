#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>

#include <dircontents.h>

int main(int argc, char **argv)
{
    char path[255] = {0};
    char command[255] = {"current"};
    printf("Print full path to the directory.\nIf you want to see the contents of the current directory, print current\n");
    scanf(" %[^\n]s", path);
    if(strcmp (path, command) == 0)
    {
        getcwd(path, 255);
    }

    
    printf("path = %s\n", path);

    print_dir_contents(path);


    return 0;
}