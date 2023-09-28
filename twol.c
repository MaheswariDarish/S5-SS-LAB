#include <stdio.h>
#include <string.h>

struct File {
    char filename[50];
};

struct Directory {
    char dirname[50];
    struct File files[10]; // Assuming 10 files in each directory
    int fileCount;
};

int main() {
    struct Directory twoLevel[10]; // Assuming 10 directories
    int dirCount = 0;

    // Create directories and files in the two-level directory structure
    strcpy(twoLevel[dirCount].dirname, "directory1");
    strcpy(twoLevel[dirCount].files[twoLevel[dirCount].fileCount++].filename, "file1.txt");
    strcpy(twoLevel[dirCount].files[twoLevel[dirCount].fileCount++].filename, "file2.txt");
    dirCount++;

    strcpy(twoLevel[dirCount].dirname, "directory2");
    strcpy(twoLevel[dirCount].files[twoLevel[dirCount].fileCount++].filename, "file3.txt");
    // Add more directories and files as needed

    // List files in the two-level directory structure
    printf("Two-Level Directory Structure:\n");
    for (int i = 0; i < dirCount; i++) {
        printf("Directory: %s\n", twoLevel[i].dirname);
        for (int j = 0; j < twoLevel[i].fileCount; j++) {
            printf("File: %s\n", twoLevel[i].files[j].filename);
        }
    }

    return 0;
}
