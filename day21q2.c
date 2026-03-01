//https://leetcode.com/problems/middle-of-the-linked-list/description/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode *a = head;
    struct ListNode *b= head;

    while (b != NULL && b->next != NULL) {
        a=a->next;       
        b =b->next->next;   
    }

    return a;
}