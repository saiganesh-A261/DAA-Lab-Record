/*
Title: Linear Search
Aim: To perform linear search on an array and measure execution time.

Algorithm:
1. Generate array of size n with random values
2. Generate a key present in array
3. Start timer
4. Compare each element with key
5. If found print position
6. Stop timer
7. Display time taken
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void ls(int a[], int begin, int stop, int search)
{
    if(begin == stop)
        printf("Element not found");
    else if(a[begin] == search)
        printf("Element found at position %d", begin+1);
    else
        ls(a, begin+1, stop, search);
}

int main()
{
    int a[10000], n=10000, key, i;
    clock_t start, end;

    for(i=0;i<n;i++)
        a[i]=rand()%1000;

    key = a[rand()%n];

    start = clock();
    ls(a, 0, n, key);
    end = clock();

    printf("\nTime taken: %lf", (double)(end-start));

    return 0;
}

// Code By @saiganesh-scsvmv
