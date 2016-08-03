class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        if(preorder.empty()) return true;
        stack<int> sta;
        sta.push(preorder[0]);
        int cur = INT_MIN;
        for(int i=1; i<preorder.size(); i++){
            if(sta.empty() || sta.top()>preorder[i]){
                if(cur >= preorder[i]) return false;
                sta.push(preorder[i]);
            }else{
                while(!sta.empty() && sta.top()<preorder[i]){
                    cur = sta.top();
                    sta.pop();
                }
                sta.push(preorder[i]);
            }
        }
        return true;
    }
};


