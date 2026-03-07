/*Problem: Implement push and pop operations on a stack and verify stack operations.

Input:
- First line: integer n
- Second line: n integers to push
- Third line: integer m (number of pops)

Output:
- Print remaining stack elements from top to bottom

Example:
Input:
5
10 20 30 40 50
2

Output:
30 20 10*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int stack[MAX];
int top = -1;

void push(int value) {
    if (top < MAX - 1) {
        stack[++top] = value;
    }
}

void pop() {
    if (top >= 0) {
        top--;
    }
}

int main() {
    int n, m, value;

    if (scanf("%d", &n) != 1) return 0;

    for (int i = 0; i < n; i++) {
        if (scanf("%d", &value) == 1) {
            push(value);
        }
    }

    if (scanf("%d", &m) != 1) return 0;

    for (int i = 0; i < m; i++) {
        pop();
    }

    for (int i = top; i >= 0; i--) {
        printf("%d%c", stack[i], (i == 0 ? '\n' : ' '));
    }

    return 0;
}