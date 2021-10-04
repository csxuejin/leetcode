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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
         int index = 1; 
         ListNode *newHead = new ListNode(-1);
         newHead->next = head;
         ListNode *t = newHead;
         while(index < m){
             t = t->next;
             index++;
         }
         ListNode *pre = t->next;
         ListNode *cur = t->next->next;
         index++;
         while(index <= n && cur){
             ListNode *tmpNode = cur->next;
             cur->next = pre;
             pre = cur;
             cur = tmpNode;
             index++;
         }
         t->next->next = cur;
         t->next = pre;
         return newHead->next;
    }
};