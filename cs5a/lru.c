#include <stdio.h>

int main() {
    int n, frames, i, j, hit, fault, min, index, counter;
    
    printf("Enter the number of pages: ");
    scanf("%d", &n);
    
    printf("Enter the number of frames: ");
    scanf("%d", &frames);
    
    int pages[n], memory[frames], lru[frames];
    
    printf("Enter the page reference sequence:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    for (i = 0; i < frames; i++) {
        memory[i] = -1; // Initialize memory with empty frames
        lru[i] = 0; // Initialize LRU counter
    }

    hit = 0;
    fault = 0;
    counter = 1;

    for (i = 0; i < n; i++) {
        int page = pages[i];
        int found = 0;

        // Check if page is already in memory
        for (j = 0; j < frames; j++) {
            if (memory[j] == page) {
                hit++;
                lru[j] = counter++;
                found = 1;
                break;
            }
        }

        // Page is not in memory, find least recently used page
        if (!found) {
            min = lru[0];
            index = 0;
            for (j = 1; j < frames; j++) {
                if (lru[j] < min) {
                    min = lru[j];
                    index = j;
                }
            }

            memory[index] = page;
            lru[index] = counter++;
            fault++;
        }

        // Print the current state of memory
        printf("Memory: ");
        for (j = 0; j < frames; j++) {
            if (memory[j] != -1) {
                printf("%d ", memory[j]);
            }
        }
        printf("\n");
    }

    printf("Total Page Hits: %d\n", hit);
    printf("Total Page Faults: %d\n", fault);

    return 0;
}
