//https://leetcode.com/problems/basic-calculator-ii/description/

int calculate(char* s) {
    int n = strlen(s);
    if (n == 0) return 0;

    int* stack = (int*)malloc(sizeof(int) * n);
    int top = -1;
    
    long currentNumber = 0;
    char lastOperator = '+';

    for (int i = 0; i <= n; i++) {
        char c = (i < n) ? s[i] : '\0';

        if (isdigit(c)) {
            currentNumber = currentNumber * 10 + (c - '0');
        }

        if ((!isdigit(c) && !isspace(c)) || i == n) {
            if (lastOperator == '+') {
                stack[++top] = currentNumber;
            } else if (lastOperator == '-') {
                stack[++top] = -currentNumber;
            } else if (lastOperator == '*') {
                stack[top] = stack[top] * currentNumber;
            } else if (lastOperator == '/') {
                stack[top] = stack[top] / currentNumber;
            }
            
            lastOperator = c;
            currentNumber = 0;
        }
    }

    int result = 0;
    for (int i = 0; i <= top; i++) {
        result += stack[i];
    }

    free(stack);
    return result;
}