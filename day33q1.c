/*Problem: Convert an infix expression to postfix notation using stack.

Input:
- Single line: infix expression (operands are single characters)

Output:
- Print the postfix expression

Example:
Input:
A+B*C

Output:
ABC*+

Explanation:
Operator precedence: * > +
Use stack to handle operator precedence and associativity*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Node {
    char data;
    struct Node *left, *right;
};

struct Node* createNode(char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void postOrder(struct Node* root) {
    if (root) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%c", root->data);
    }
}

int main() {
    char postfix[] = "ABC*+"; 
    struct Node* stack[100];
    int top = -1;

    for (int i = 0; postfix[i] != '\0'; i++) {
        struct Node* newNode = createNode(postfix[i]);
        if (isalnum(postfix[i])) {
            stack[++top] = newNode;
        } else {
            newNode->right = stack[top--];
            newNode->left = stack[top--];
            stack[++top] = newNode;
        }
    }

    struct Node* root = stack[top];
    postOrder(root);
    printf("\n");

    return 0;
}