#include <stdio.h>
#include <string.h>

struct File {
    char filename[50];
};

struct Directory {
    char dirname[50];
    struct File files[10]; // Assuming 10 files in each directory
    int fileCount;
    struct Directory* subdirs[10]; // Assuming 10 subdirectories
    int subdirCount;
};

// Function to list files and subdirectories recursively
void listDirectory(struct Directory* dir) {
    printf("Directory: %s\n", dir->dirname);
    for (int i = 0; i < dir->fileCount; i++) {
        printf("File: %s\n", dir->files[i].filename);
    }
    for (int i = 0; i < dir->subdirCount; i++) {
        listDirectory(dir->subdirs[i]);
    }
}

int main() {
    struct Directory root;
    strcpy(root.dirname, "root");
    root.fileCount = 0;
    root.subdirCount = 0;

    // Create subdirectories and files in the hierarchical directory structure
    struct Directory* subdir1 = &root.subdirs[root.subdirCount++];
    strcpy(subdir1->dirname, "subdir1");
    subdir1->fileCount = 0;

    strcpy(subdir1->files[subdir1->fileCount++].filename, "file1.txt");
    strcpy(subdir1->files[subdir1->fileCount++].filename, "file2.txt");

    // Add more subdirectories and files as needed

    // List files and subdirectories in the hierarchical directory structure
    printf("Hierarchical Directory Structure:\n");
    listDirectory(&root);

    return 0;
}
