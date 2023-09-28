#include <stdio.h>

int main() {
    int n, frames, i, j, hit, fault, pos, flag;
    
    printf("Enter the number of pages: ");
    scanf("%d", &n);
    
    printf("Enter the number of frames: ");
    scanf("%d", &frames);
    
    int pages[n], memory[frames];
    
    printf("Enter the page reference sequence:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    for (i = 0; i < frames; i++) {
        memory[i] = -1; // Initialize memory with empty frames
    }

    hit = 0;
    fault = 0;
    pos = 0; // Position to replace in the memory

    for (i = 0; i < n; i++) {
        flag = 0;

        // Check if page is already in memory
        for (j = 0; j < frames; j++) {
            if (memory[j] == pages[i]) {
                hit++;
                flag = 1;
                break;
            }
        }

        // Page is not in memory, replace
        if (flag == 0) {
            memory[pos] = pages[i];
            fault++;
            pos = (pos + 1) % frames; // Move the position circularly
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
