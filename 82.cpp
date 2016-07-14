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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) 
            return head;
        ListNode *newHead = new ListNode(-1);
        newHead->next = head;
        ListNode *cur = newHead; 
        while(cur->next && cur->next->next){
            if(cur->next->val != cur->next->next->val){
                cur = cur->next;
            }else{
                int t = cur->next->val;
                while(cur->next && cur->next->val == t){
                    cur->next = cur->next->next;
                }
            }
        }
        return newHead->next;
    }
};