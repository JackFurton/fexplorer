#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include "directory.h"
#include "file.h"

int main() {
    char currentDirectory[4096];
    getcwd(currentDirectory, sizeof(currentDirectory));

    char input[4096];
    while (1) {
        printf("\nCurrent Directory: %s\n", currentDirectory);
        printf("Options:\n1. List Files\n2. Change Directory\n3. Enter file to be read\nYour choice: ");
        fgets(input, sizeof(input), stdin);
        input[strlen(input) - 1] = '\0';

        if (strcmp(input, "1") == 0) {
            list_files(currentDirectory);

        } else if (strcmp(input, "2") == 0) {
            printf("Enter new directory: ");
            fgets(input, sizeof(input), stdin);
            input[strlen(input) - 1] = '\0';
            DIR *dir = opendir(input);

            if (dir) {
                closedir(dir);
                strcpy(currentDirectory, input);
            } else {
                printf("Directory does not exist.\n");
	    }

	} else if (strcmp(input, "3") == 0) {
	   printf("Enter filename: ");
	   fgets(input, sizeof(input), stdin);
	   input[strlen(input) - 1] = '\0';
	   display_file_contents(input);
            
        } else {
            printf("Invalid input.\n");
        }
    }
    return 0;
}
