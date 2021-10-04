class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> sta;
        heights.push_back(0);
        int ans = 0;
        for(int i=0; i<heights.size(); i++){
            while(!sta.empty() && heights[i]<=heights[sta.top()]){
                int h = heights[sta.top()];
                sta.pop();
                int tmp = h *( sta.empty()? i:i-sta.top()-1 );
                ans = max(ans, tmp);
            }
            sta.push(i);
        }
        return ans;
    }
};