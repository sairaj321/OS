#include <stdio.h>

int main() {
    int q[20], p[50], c = 0, f, n, page_hits = 0;
	float ratio_faults=0;
	float ratio_hits=0;
    printf("Enter no of pages:");
    scanf("%d", &n);

    printf("Enter the reference string:");
    for (int i = 0; i < n; i++)
        scanf("%d", &p[i]);

    printf("Enter no of frames:");
    scanf("%d", &f);

    int lru[f];  // Array to store the last used index of each frame

    for (int i = 0; i < f; i++) {
        q[i] = -1;  // Initialize frames with -1 to indicate empty slots
        lru[i] = 0; // Initialize the last used index of each frame to 0
    }

    for (int i = 0; i < n; i++) {
        int page = p[i];
        int found = 0;

        // Check if the page is already in the frame
        for (int j = 0; j < f; j++) {
            if (q[j] == page) {
                page_hits++;
                found = 1;
                lru[j] = i; // Update the last used index
                break;
            }
        }

        if (!found) {
            int replace_index = 0;

            // Find the frame with the least recently used page
            for (int j = 1; j < f; j++) {
                if (lru[j] < lru[replace_index]) {
                    replace_index = j;
                }
            }

            q[replace_index] = page;
            lru[replace_index] = i; // Update the last used index
            c++;
        }

        // Print the current frames
        for (int j = 0; j < f; j++) {
            printf("\t%d", q[j]);
        }
        printf("\n");
    }
    ratio_faults = (float)c / n;
    ratio_hits = (float)page_hits / n;
    printf("\nThe no of page faults is %d\n", c);
    printf("The no of page hits is %d\n", page_hits);
	printf("Page faults ratio: %f\n", ratio_faults);
    printf("Page hits ratio: %f\n", ratio_hits);

    return 0;
}
