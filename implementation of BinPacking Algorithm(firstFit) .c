#include <stdio.h>

void firstFit(int items[], int n, int capacity)
{
    int bin[n];        // Remaining capacity of bins
    int binCount = 0;  // Number of bins used

    printf("\nExecuting First Fit Algorithm\n");

    // Initialize all bins with 0 (means unused)
    for (int i = 0; i < n; i++)
        bin[i] = 0;

    // Process each item
    for (int i = 0; i < n; i++)
    {
        // If item size exceeds bin capacity
        if (items[i] > capacity)
        {
            printf("Item %d (size %d) cannot be placed in any bin\n", i + 1, items[i]);
            continue;
        }

        int placed = 0;

        // Try to place item in existing bins
        for (int j = 0; j < binCount; j++)
        {
            if (bin[j] >= items[i])
            {
                bin[j] -= items[i];
                printf("Item %d placed in Bin %d\n", items[i], j + 1);
                placed = 1;
                break;
            }
        }

        // If not placed, create a new bin
        if (!placed)
        {
            bin[binCount] = capacity - items[i];
            printf("Item %d placed in Bin %d\n", items[i], binCount + 1);
            binCount++;
        }
    }

    printf("Total bins used = %d\n", binCount);
}

int main()
{
    int n, capacity;

    printf("Enter number of items: ");
    scanf("%d", &n);

    int items[n];  // Variable Length Array (VLA)

    printf("Enter item sizes:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Item %d: ", i + 1);
        scanf("%d", &items[i]);
    }

    printf("Enter bin capacity: ");
    scanf("%d", &capacity);

    firstFit(items, n, capacity);

    return 0;
}

// Code By @saiganesh-A261
