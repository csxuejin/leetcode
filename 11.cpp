class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size()-1;
        int res = INT_MIN;
        while(l<r){
            int h = min(height[l],height[r]);
            res =max(res, h*(r-l));
            while(l<r && height[l]<=h) l++;
            while(l<r && height[r]<=h) r--;
        }
        return res;
    }
};