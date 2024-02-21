#include <stdio.h>

void display_file_contents(const char *filepath) {
    FILE *file = fopen(filepath, "r"); // open the file for reading
    if (file == NULL) {
        printf("Cannot open file: %s\n", filepath);
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);
    }

    fclose(file);
}
