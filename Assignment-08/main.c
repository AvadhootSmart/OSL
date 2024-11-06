#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100

// Function to calculate the absolute difference
int abs_diff(int a, int b) {
    return abs(a - b);
}

// Function for SSTF (Shortest Seek Time First) Disk Scheduling
void SSTF(int arr[], int n, int head) {
    int distance[MAX], completed[MAX], count = 0, total_distance = 0, min, index;

    // Initialize all the requests as unprocessed
    for (int i = 0; i < n; i++) {
        completed[i] = 0;
    }

    while (count < n) {
        min = 999999;  // Set a large value for minimum distance

        // Find the closest unprocessed request
        for (int i = 0; i < n; i++) {
            if (!completed[i]) {
                distance[i] = abs_diff(arr[i], head);
                if (distance[i] < min) {
                    min = distance[i];
                    index = i;
                }
            }
        }

        // Update the total distance and the current head position
        completed[index] = 1;
        total_distance += distance[index];
        head = arr[index];
        count++;
    }

    printf("\nTotal Seek Time for SSTF: %d\n", total_distance);
}

// Function for SCAN Disk Scheduling
void SCAN(int arr[], int n, int head, int disk_size) {
    int left[MAX], right[MAX], total_distance = 0, count = 0;
    int i = 0, j = 0;

    // Separate the requests into left and right of the head
    for (int k = 0; k < n; k++) {
        if (arr[k] < head) {
            left[i++] = arr[k];
        } else {
            right[j++] = arr[k];
        }
    }

    // Sort the left and right requests
    for (i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (left[j] > left[j + 1]) {
                int temp = left[j];
                left[j] = left[j + 1];
                left[j + 1] = temp;
            }
        }
    }

    for (i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (right[j] > right[j + 1]) {
                int temp = right[j];
                right[j] = right[j + 1];
                right[j + 1] = temp;
            }
        }
    }

    // Traverse right side (away from spindle)
    total_distance += abs_diff(head, right[0]);
    head = right[0];

    for (i = 1; i < j; i++) {
        total_distance += abs_diff(head, right[i]);
        head = right[i];
    }

    // Traverse left side (towards spindle)
    total_distance += abs_diff(head, left[0]);
    head = left[0];

    for (i = 1; i < i; i++) {
        total_distance += abs_diff(head, left[i]);
        head = left[i];
    }

    printf("\nTotal Seek Time for SCAN: %d\n", total_distance);
}

// Function for C-Look Disk Scheduling
void CLook(int arr[], int n, int head, int disk_size) {
    int left[MAX], right[MAX], total_distance = 0, count = 0;
    int i = 0, j = 0;

    // Separate the requests into left and right of the head
    for (int k = 0; k < n; k++) {
        if (arr[k] < head) {
            left[i++] = arr[k];
        } else {
            right[j++] = arr[k];
        }
    }

    // Sort the left and right requests
    for (i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (left[j] > left[j + 1]) {
                int temp = left[j];
                left[j] = left[j + 1];
                left[j + 1] = temp;
            }
        }
    }

    for (i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (right[j] > right[j + 1]) {
                int temp = right[j];
                right[j] = right[j + 1];
                right[j + 1] = temp;
            }
        }
    }

    // Move in the right direction (away from the spindle)
    total_distance += abs_diff(head, right[0]);
    head = right[0];

    for (i = 1; i < j; i++) {
        total_distance += abs_diff(head, right[i]);
        head = right[i];
    }

    // Jump to the beginning of the left side and process it
    total_distance += abs_diff(head, left[0]);
    head = left[0];

    for (i = 1; i < i; i++) {
        total_distance += abs_diff(head, left[i]);
        head = left[i];
    }

    printf("\nTotal Seek Time for C-Look: %d\n", total_distance);
}

int main() {
    int n, head, disk_size;
    int arr[MAX];

    // Input disk requests and initial head position
    printf("Enter the number of disk requests: ");
    scanf("%d", &n);

    printf("Enter the disk size (total number of cylinders): ");
    scanf("%d", &disk_size);

    printf("Enter the initial head position: ");
    scanf("%d", &head);

    printf("Enter the disk requests: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Run SSTF algorithm
    SSTF(arr, n, head);

    // Run SCAN algorithm
    SCAN(arr, n, head, disk_size);

    // Run C-Look algorithm
    CLook(arr, n, head, disk_size);

    return 0;
}
