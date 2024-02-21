#include <stdlib.h>
#include <dirent.h>
#include <stdio.h>
#include <sys/stat.h>
#include "directory.h"

void list_files(const char *path) {
    struct dirent *entry;
    struct stat fileStat;
    DIR *dir = opendir(path);

    if (dir == NULL) {
        return;
    }
    while ((entry = readdir(dir)) != NULL) {
        stat(entry->d_name,&fileStat);   
        printf("%s , size: %d bytes\n", entry->d_name, fileStat.st_size);
    }

    closedir(dir);
}
