#include <stdio.h>

/*
Program: First Fit Bin Packing Algorithm
Description: Places each item into the first available bin that has enough space.
             If no bin fits, a new bin is created.
Author: Sai Ganesh (@saiganesh-A261)
*/

void firstFit(int items[], int n, int capacity)
{
    int bin[n];        // Stores remaining capacity of each bin
    int binCount = 0;  // Tracks number of bins currently used

    printf("\nExecuting First Fit Algorithm\n");

    // Initialize all bins as unused (0 remaining capacity)
    for (int i = 0; i < n; i++)
        bin[i] = 0;

    // Traverse each item
    for (int i = 0; i < n; i++)
    {
        // Check if item itself exceeds bin capacity
        if (items[i] > capacity)
        {
            printf("Item %d (size %d) cannot be placed in any bin\n", i + 1, items[i]);
            continue;
        }

        int placed = 0; // Flag to check if item is placed

        // Try placing item in existing bins (First Fit logic)
        for (int j = 0; j < binCount; j++)
        {
            // If current bin has enough space
            if (bin[j] >= items[i])
            {
                bin[j] -= items[i]; // Reduce available space
                printf("Item %d placed in Bin %d\n", items[i], j + 1);
                placed = 1;
                break; // Stop at first suitable bin
            }
        }

        // If item is not placed in any existing bin
        if (!placed)
        {
            // Create new bin and assign remaining capacity
            bin[binCount] = capacity - items[i];
            printf("Item %d placed in Bin %d\n", items[i], binCount + 1);
            binCount++;
        }
    }

    // Display total number of bins used
    printf("Total bins used = %d\n", binCount);
}

int main()
{
    int n, capacity;

    // Input number of items
    printf("Enter number of items: ");
    scanf("%d", &n);

    int items[n];  // Variable Length Array (VLA)

    // Input item sizes
    printf("Enter item sizes:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Item %d: ", i + 1);
        scanf("%d", &items[i]);
    }

    // Input bin capacity
    printf("Enter bin capacity: ");
    scanf("%d", &capacity);

    // Execute First Fit algorithm
    firstFit(items, n, capacity);

    return 0;
}

// Code By @saiganesh-A261