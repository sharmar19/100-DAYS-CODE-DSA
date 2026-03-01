/*Problem: Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list)

Output:
- Print value of intersection node or 'No Intersection'

Example:
Input:
5
10 20 30 40 50
4
15 25 30 40 50

Output:
30

Explanation:
Calculate lengths, advance pointer in longer list, traverse both simultaneously. First common node is intersection.*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

int getLength(struct Node* head) {
    int len = 0;
    while (head != NULL) {
        len++;
        head = head->next;
    }
    return len;
}

struct Node* buildList(int n) {
    if (n <= 0) return NULL;
    struct Node *head = NULL, *tail = NULL;
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        struct Node* newNode = createNode(val);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

void findIntersection(struct Node* head1, struct Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    struct Node* curr1 = head1;
    struct Node* curr2 = head2;

    if (len1 > len2) {
        for (int i = 0; i < len1 - len2; i++) curr1 = curr1->next;
    } else {
        for (int i = 0; i < len2 - len1; i++) curr2 = curr2->next;
    }

    while (curr1 != NULL && curr2 != NULL) {
        if (curr1->data == curr2->data) {
            printf("%d\n", curr1->data);
            return;
        }
        curr1 = curr1->next;
        curr2 = curr2->next;
    }

    printf("No Intersection\n");
}

int main() {
    int n, m;

    if (scanf("%d", &n) != 1) return 0;
    struct Node* list1 = buildList(n);

    if (scanf("%d", &m) != 1) return 0;
    struct Node* list2 = buildList(m);

    findIntersection(list1, list2);

    return 0;
}
