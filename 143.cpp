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
    ListNode* reverseList(ListNode *head){
        ListNode *pre = head;
        ListNode *cur = head->next;
        while(cur){
            ListNode *t = cur->next;
            cur->next = pre;
            pre = cur;
            cur = t;
        }
        head->next = NULL;
        return pre;
    }
    void reorderList(ListNode* head) {
        if(!head || !head->next) 
            return;
        ListNode *slow = head;
        ListNode *fast = head->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *h1 = head;
        ListNode *h2 = reverseList(slow->next);
        slow->next = NULL;
        while(h1 && h2){
            ListNode *next1 = h1->next;
            ListNode *next2 = h2->next;
            h1->next = h2;
            h2->next = next1;
            h1 = next1;
            h2 = next2;
        }
    }
};