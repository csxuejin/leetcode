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
    bool isPalindrome(ListNode* head) {
         if(!head || !head->next) 
            return true;
         ListNode *slow = head;
         ListNode *fast = head;
         while(fast->next && fast->next->next){
             slow = slow->next;
             fast = fast->next->next;
         }
         ListNode *newHead = reverseList(slow->next);
         while(newHead){
             if(newHead->val != head->val){
                 return false;
             }
             newHead = newHead->next;
             head = head->next;
         }
         return true;
    }
    
    ListNode* reverseList(ListNode *head){
        ListNode *next = NULL;
        ListNode *pre = NULL;
        while(head){
            next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        return pre;
    }
    
};