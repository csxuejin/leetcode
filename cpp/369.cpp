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
    ListNode* reverse(ListNode* head){
        if(!head || !head->next)
            return head;
        ListNode* last = head;
        ListNode* cur = head->next;
        while(cur){
            ListNode* t = cur->next;
            cur->next = last;
            last = cur;
            cur = t;
        }
        head->next = NULL;
        return last;
    }
    
    ListNode* plusOne(ListNode* head) {
        if(!head)
            return new ListNode(1);
        ListNode* newHead = reverse(head);
        int sum = newHead->val + 1;
        newHead->val = sum%10;
        int last = sum/10;
        ListNode* t = newHead->next;
        while(last && t){
            sum = t->val + last;
            t->val = sum%10;
            last = sum/10;
            t = t->next;
        }
        ListNode *res = reverse(newHead);
        if(last){
            ListNode *tNode = new ListNode(last);
            tNode->next = res;
            res = tNode;
        }
        return res;
    }
};


