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
    ListNode* insertionSortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *newHead = new ListNode(head->val);
        
        head = head->next;
        while(head){
            if(head->val < newHead->val){
                ListNode *t = new ListNode(head->val);
                t->next = newHead;
                newHead = t;
            }else{
                ListNode *last = newHead;
                ListNode *cur = newHead->next;
                while(cur && head->val>cur->val){
                    last = cur;
                    cur = cur->next;
                }
                ListNode *t = new ListNode(head->val);
                last->next = t;
                t->next = cur;
            }
            head = head->next;
        }
        return newHead;
    }
};

