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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k==0) 
            return head;
        int cnt = 1; 
        ListNode *t = head;
        while(t->next){
            t = t->next;
            cnt++;
        }
        ListNode *last = t;
        k = cnt - k%cnt;
        if(k==cnt) 
            return head;
        t = head;
        for(int i=1; i<k; i++){
            t = t->next;
        }
        ListNode *newHead = t->next;
        t->next = NULL;
        last->next = head;
        return newHead;
    }
};






