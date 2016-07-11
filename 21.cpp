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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1 && !l2) return NULL;
        ListNode *head = new ListNode(-1);
        ListNode *cur = head;
        while(l1 || l2){
            if(!l1 && l2){
                cur->next = l2;
                l2 = l2->next;
            }  
            if(l1 && !l2){
                cur->next = l1;
                l1 = l1->next;
            }
            if(l1 && l2){
                if(l1->val<l2->val){
                    cur->next = l1;
                    l1 = l1->next;
                }else{
                    cur->next = l2;
                    l2 = l2->next;
                }
            } 
            cur = cur->next;
        }
        return head->next;
    }
};