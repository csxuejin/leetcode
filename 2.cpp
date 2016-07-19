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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *newHead = new ListNode(-1);
        ListNode *tmpNode = newHead;
        int last = 0;
        while(l1 || l2){
            int t = last;
            if(l1){
                t += l1->val;
                l1 = l1->next;
            }
            if(l2){
                t += l2->val;
                l2 = l2->next;
            }
            tmpNode->next = new ListNode(t%10);
            tmpNode = tmpNode->next;
            last = t/10;
        }
        if(last){
            tmpNode->next = new ListNode(last);
        }
        return newHead->next;
    }
};

