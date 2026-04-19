#include <stdio.h>

void bestFit(int items[], int n, int capacity)
{
    printf("\nBest Fit Algorithm\n");

    int bin[n];
    int binCount = 0;

    for (int i = 0; i < n; i++)
        bin[i] = capacity;

    for (int i = 0; i < n; i++)
    {
        int bestIndex = -1;
        int minSpace = capacity + 1;

        for (int j = 0; j < binCount; j++)
        {
            if (bin[j] >= items[i] && (bin[j] - items[i]) < minSpace)
            {
                bestIndex = j;
                minSpace = bin[j] - items[i];
            }
        }

        if (bestIndex != -1)
        {
            bin[bestIndex] -= items[i];
            printf("Item %d placed in Bin %d\n", items[i], bestIndex + 1);
        }
        else
        {
            bin[binCount] -= items[i];
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

    int items[n];

    printf("Enter bin capacity: ");
    scanf("%d", &capacity);

    printf("Enter item sizes:\n");

    for (int i = 0; i < n; i++)
    {
        int itemsize;
        printf("Item %d: ", i + 1);
        scanf("%d", &itemsize);

        if (itemsize <= capacity)
        {
            items[i] = itemsize;
        }
        else
        {
            printf("Item size exceeds bin capacity!\n");
            i--;
        }
    }

    bestFit(items, n, capacity);

    return 0;
}

// Code By @saiganesh-A261
