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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *tmp = head;
        int cnt = 0;
        while(tmp){
            cnt++;
            tmp = tmp->next;
        }
        tmp = head;
        if (cnt == 1) return NULL;
        if (cnt-n == 0) return head->next;
        for(int i=0; i<cnt-n; i++){
            if(i==cnt-n-1){
                if (tmp->next)
                    tmp->next = tmp->next->next;
                else
                    tmp->next = NULL;
            }else{
                tmp = tmp->next;
            }
        }
        return head;
    }
};