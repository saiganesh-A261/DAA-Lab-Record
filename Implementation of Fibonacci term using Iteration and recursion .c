/*
Title: Fibonacci using Recursion
Aim: To compute the nth Fibonacci number using recursion.

Algorithm:
1. If n == 0, return 0
2. If n == 1, return 1
3. Otherwise, return fib(n-1) + fib(n-2)
*/

#include <stdio.h>

// Function to compute Fibonacci
int fib(int n)
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return fib(n - 1) + fib(n - 2);
}

int main()
{
    int n;

    printf("Enter n value: ");
    scanf("%d", &n);

    if (n < 0)
    {
        printf("Invalid entry\n");
    }
    else
    {
        printf("Fibonacci term is: %d\n", fib(n));
    }

    return 0;
}


// Code By @saiganesh-A261
