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
        if(!head || !head->next) return head;
        ListNode *cur = head->next;
        ListNode *pre = head;
        while(cur){
           while(cur && (cur->val==pre->val) ){
               cur = cur->next;
           }
           pre->next = cur;
           pre = pre->next;
           if(cur){
               cur = cur->next;
           }
        }
        return head;
    }
};