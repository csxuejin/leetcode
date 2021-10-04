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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* newHead = new ListNode(-1);
        newHead->next = head;
        ListNode* last = newHead; 
        ListNode* start = head;
        
        int cnt = 0;
        ListNode* t = head;
        while(t){
            t = t->next;
            cnt++;
            if(cnt==k){
               ListNode* pre = start;
               ListNode* cur = start->next;
               while(cur && cur!=t){
                   ListNode * next = cur->next;
                   cur->next = pre;
                   pre = cur;
                   cur = next;
               }
               last->next = pre;
               last = start;
               start->next = t;
               start = t;
               cnt=0;
            }
        }
        return newHead->next;
    }
};
