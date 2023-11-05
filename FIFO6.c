#include <stdio.h>
#include <stdlib.h>

void page(int npages, int n, int frames[], int pages[]) {
    int page_faults = 0;
    int page_hits = 0;
    int index = 0;
    float ratio_faults, ratio_hits;

    for (int i = 0; i < npages; i++) {
        int page = pages[i];
        int page_found = 0;

        for (int j = 0; j < n; j++) {
            if (frames[j] == page) {
                page_found = 1;
                page_hits++;
                break;
            }
        }

        if (!page_found) {
            frames[index] = page;
            page_faults++;
            index = (index + 1) % n;
        }

        printf("Page frames: ");
        for (int j = 0; j < n; j++) {
            if (frames[j] == -1) {
                printf("[ ] ");
            } else {
                printf("[%d] ", frames[j]);
            }
        }
        printf("\n");
    }

    ratio_faults = (float)page_faults / npages;
    ratio_hits = (float)page_hits / npages;

    printf("Total page faults: %d\n", page_faults);
    printf("Total page hits: %d\n", page_hits);
    printf("Page faults ratio: %f\n", ratio_faults);
    printf("Page hits ratio: %f\n", ratio_hits);
}

int main() {
    int n, npages;
    printf("Enter the number of page frames: ");
    scanf("%d", &n);
    int frames[n];
    
    for (int i = 0; i < n; i++) {
        frames[i] = -1;
    }

    printf("Enter the number of pages: ");
    scanf("%d", &npages);
    int pages[npages];

    printf("Enter the page reference string: ");
    
    for (int i = 0; i < npages; i++) {
        scanf("%d", &pages[i]);
    }

    page(npages, n, frames, pages);
}
