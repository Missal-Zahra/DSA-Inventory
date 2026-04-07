#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
} Interval;

// Human-readable comparison for sorting
int compareIntervals(const void* a, const void* b) {
    return ((Interval*)a)->start - ((Interval*)b)->start;
}

// Function to get the max of two numbers
int max(int a, int b) {
    return (a > b) ? a : b;
}

void mergeIntervals(Interval intervals[], int n) {
    if (n <= 0) return;

    // 1. Sort the intervals based on start time
    qsort(intervals, n, sizeof(Interval), compareIntervals);

    // 2. Merge logic using a 'current' pointer
    int index = 0; // This tracks the last merged interval

    for (int i = 1; i < n; i++) {
        // If the current interval overlaps with the next one
        if (intervals[index].end >= intervals[i].start) {
            // Merge them: update the end to the furthest point
            intervals[index].end = max(intervals[index].end, intervals[i].end);
        } else {
            // No overlap: move to the next slot and copy the interval over
            index++;
            intervals[index] = intervals[i];
        }
    }

    // Output the result
    printf("Merged Intervals:\n");
    for (int i = 0; i <= index; i++) {
        printf("[%d, %d] ", intervals[i].start, intervals[i].end);
    }
    printf("\n");
}

int main() {
    Interval arr[] = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    int n = sizeof(arr) / sizeof(arr[0]);

    mergeIntervals(arr, n);

    return 0;
}