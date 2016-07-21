class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty())
            return vector<int>{-1,-1};
        int l, r;
        int start, end;
        start = 0;
        end = nums.size();
        while(start < end){
            int mid = (start + end)/2;
            if(nums[mid]>=target){
                end = mid;
            }else{
                start = mid+1;
            }
        }
        l = start;
        end = nums.size();
        while(start < end){
            int mid = (start+end)/2;
            if(nums[mid]<=target){
                start = mid+1;
            }else{
                end = mid;
            }
        }
        r = start;
        return l==r? vector<int>{-1,-1}:vector<int>{l,r-1};
    }
};
