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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode *oddHead = head;
        ListNode *t1 = oddHead;
        ListNode *evenHead = head->next;
        ListNode *t2 = evenHead;
        while(t2 && t2->next){
            t1->next = t2->next;
            t2->next = t2->next->next;
            t1 = t1->next;
            t2 = t2->next;
        }
        t1->next = evenHead;
        return oddHead;
    }
};
