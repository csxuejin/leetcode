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
    struct cmp{
       bool operator () (ListNode * a, ListNode * b){
           return a->val > b->val;
       }  
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return NULL;
        priority_queue<ListNode*, vector<ListNode*>,cmp> que;
        for(int i=0; i<lists.size(); i++){
            if(lists[i])
                que.push(lists[i]);
        }
        if(que.empty()) return NULL;
        ListNode* head = que.top();
        ListNode* tail = NULL;
        while(!que.empty()){
            ListNode* t = que.top();
            if(tail) tail->next = t;
            tail = t;
            que.pop();
            if(t->next) 
                que.push(t->next);
        }
        return head;
    }
};
