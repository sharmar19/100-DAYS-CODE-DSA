/*Problem: Write a program to find the maximum and minimum values present in a given array of integers.

Input:
- First line: integer n
- Second line: n integers

Output:
- Print the maximum and minimum elements

Example:
Input:
6
3 5 1 9 2 8

Output:
Max: 9
Min: 1*/

#include <stdio.h>
#include <limits.h>

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int max = INT_MIN;
    int min = INT_MAX;

    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        if (num > max) max = num;
        if (num < min) min = num;
    }

    printf("Max: %d\n", max);
    printf("Min: %d\n", min);

    return 0;
}