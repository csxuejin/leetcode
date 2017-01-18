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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *tmp = new ListNode(-1);
        ListNode *pre = tmp;
        ListNode *cur = head;
        while(cur){
            while(cur && cur->val==val){
                cur = cur->next;
            }
            pre->next = cur;
            pre = pre->next;
            if(cur){
                cur = cur->next;
            }
        }
        return tmp->next;
    }
};