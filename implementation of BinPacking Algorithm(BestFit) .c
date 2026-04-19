#include <stdio.h>

// Function to implement Best Fit Bin Packing
void bestFit(int items[], int n, int capacity)
{
    printf("\nBest Fit Algorithm\n");

    int bin[n];       // Array to store remaining capacity of each bin
    int binCount = 0; // Number of bins currently used

    // Initially, all bins have full capacity
    for (int i = 0; i < n; i++)
        bin[i] = capacity;

    // Traverse each item
    for (int i = 0; i < n; i++)
    {
        int bestIndex = -1;           // Stores index of best bin for current item
        int minSpace = capacity + 1;  // Track minimum leftover space after placing item

        // Check all existing bins to find the best fit
        for (int j = 0; j < binCount; j++)
        {
            // Check if item fits AND leaves minimum unused space
            if (bin[j] >= items[i] && (bin[j] - items[i]) < minSpace)
            {
                bestIndex = j;
                minSpace = bin[j] - items[i];
            }
        }

        // If a suitable bin is found
        if (bestIndex != -1)
        {
            bin[bestIndex] -= items[i]; // Reduce available space in that bin
            printf("Item %d placed in Bin %d\n", items[i], bestIndex + 1);
        }
        else
        {
            // No bin found → create new bin
            bin[binCount] -= items[i];
            printf("Item %d placed in Bin %d\n", items[i], binCount + 1);
            binCount++; // Increase bin count
        }
    }

    // Print total bins used
    printf("Total bins used = %d\n", binCount);
}

int main()
{
    int n, capacity;

    // Input number of items
    printf("Enter number of items: ");
    scanf("%d", &n);

    int items[n]; // Array to store item sizes

    // Input bin capacity
    printf("Enter bin capacity: ");
    scanf("%d", &capacity);

    printf("Enter item sizes:\n");

    // Input item sizes with validation
    for (int i = 0; i < n; i++)
    {
        int itemsize;
        printf("Item %d: ", i + 1);
        scanf("%d", &itemsize);

        // Ensure item size does not exceed bin capacity
        if (itemsize <= capacity)
        {
            items[i] = itemsize;
        }
        else
        {
            printf("Item size exceeds bin capacity!\n");
            i--; // Retry same index
        }
    }

    // Call Best Fit function
    bestFit(items, n, capacity);

    return 0;
}

// Code By @saiganesh-A261