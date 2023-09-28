#include <stdio.h>
#include <stdlib.h>

// Define structures for file allocation
struct SequentialAllocation {
    int fileSize;
};

struct IndexedAllocation {
    int indexBlock;
    int fileSize;
};

struct LinkedAllocation {
    struct LinkedAllocation* nextBlock;
    int fileSize;
};

// Function to simulate sequential allocation
void sequentialAllocation() {
    struct SequentialAllocation files[10]; // Assuming 10 files
    int fileCount = 0;

    // Allocate files sequentially
    files[fileCount++].fileSize = 100;
    files[fileCount++].fileSize = 200;
    // Add more files as needed

    // Print allocated files
    printf("Sequential Allocation:\n");
    for (int i = 0; i < fileCount; i++) {
        printf("File %d: Size %d\n", i + 1, files[i].fileSize);
    }
}

// Function to simulate indexed allocation
void indexedAllocation() {
    struct IndexedAllocation files[10]; // Assuming 10 files
    int fileCount = 0;

    // Allocate files using an index block
    files[fileCount].indexBlock = 1;
    files[fileCount++].fileSize = 100;
    files[fileCount].indexBlock = 2;
    files[fileCount++].fileSize = 200;
    // Add more files as needed

    // Print allocated files
    printf("\nIndexed Allocation:\n");
    for (int i = 0; i < fileCount; i++) {
        printf("File %d: Size %d, Index Block %d\n", i + 1, files[i].fileSize, files[i].indexBlock);
    }
}

// Function to simulate linked allocation
void linkedAllocation() {
    struct LinkedAllocation* head = NULL;
    int fileSizes[] = {100, 200}; // Assuming file sizes
    int fileCount = sizeof(fileSizes) / sizeof(fileSizes[0]);

    // Allocate files using linked blocks
    for (int i = 0; i < fileCount; i++) {
        struct LinkedAllocation* newBlock = (struct LinkedAllocation*)malloc(sizeof(struct LinkedAllocation));
        newBlock->fileSize = fileSizes[i];
        newBlock->nextBlock = NULL;

        if (head == NULL) {
            head = newBlock;
        } else {
            struct LinkedAllocation* current = head;
            while (current->nextBlock != NULL) {
                current = current->nextBlock;
            }
            current->nextBlock = newBlock;
        }
    }

    // Print allocated files
    printf("\nLinked Allocation:\n");
    struct LinkedAllocation* current = head;
    int i = 1;
    while (current != NULL) {
        printf("File %d: Size %d\n", i++, current->fileSize);
        current = current->nextBlock;
    }
}

int main() {
    sequentialAllocation();
    indexedAllocation();
    linkedAllocation();

    return 0;
}
