/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *left = new ListNode(0), *right = new ListNode(0);
        ListNode *leftHead = left, *rightHead = right;
        while(head){
            // The next line is important. Pay attention to "&".
            ListNode*& ref = head->val<x? left:right;
            ref->next = head;
            ref = ref->next;
            head = head->next;
        }
        left->next = rightHead->next;
        right->next = NULL;
        return leftHead->next;
    }
};
