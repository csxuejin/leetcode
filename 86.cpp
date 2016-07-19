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
        ListNode *newHead = new ListNode(0);
        ListNode *p = newHead;
        ListNode *t = head;
        while(t){
            if(t->val < x){
                p->next = new ListNode(t->val);
                p = p->next;
            }
            
            t = t->next;
        }
        t = head;
        while(t){
            if(t->val >= x){
                p->next = new ListNode(t->val);
                p = p->next;
            }
            t = t->next;
        }
        return newHead->next;
    }
};