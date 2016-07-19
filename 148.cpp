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
    ListNode* merge(ListNode* h1, ListNode* h2){
        ListNode *newHead = new ListNode(-1);
        ListNode *t = newHead;
        while(h1 || h2){
            if(h1 && (!h2 || h1->val<=h2->val) ){
                t->next = h1;
                h1 = h1->next;
                t = t->next;
            }
            if(h2 && (!h1 || h2->val<h1->val) ){
                t->next = h2;
                h2 = h2->next;
                t = t->next;
            }
        }
        t->next = NULL;
        return newHead->next;
    }

    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) 
            return head;
        ListNode *slow = head;
        ListNode *fast = head->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *head2 = slow->next;
        slow->next = NULL;
        return merge(sortList(head), sortList(head2));
    }
};