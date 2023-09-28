#include <stdio.h>
#include <string.h>

struct File {
    char filename[50];
};

int main() {
    struct File singleLevel[10]; // Assuming 10 files in the single-level directory
    int fileCount = 0;

    // Create files in the single-level directory
    strcpy(singleLevel[fileCount++].filename, "file1.txt");
    strcpy(singleLevel[fileCount++].filename, "file2.txt");
    // Add more files as needed

    // List files in the single-level directory
    printf("Single-Level Directory:\n");
    for (int i = 0; i < fileCount; i++) {
        printf("%s\n", singleLevel[i].filename);
    }

    return 0;
}
