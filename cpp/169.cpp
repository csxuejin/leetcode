class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res, cnt = 0;
        for(int i=0; i<nums.size(); i++){
            if(cnt==0){
                res = nums[i];
                cnt = 1;
            }else{
                cnt = res==nums[i]? cnt+1:cnt-1;
            }
        }
        return res;
    }
};

/*
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> mm;
        int res;
        for (int i=0; i<nums.size(); i++){
            if(++mm[nums[i]] > nums.size()/2){
                res = nums[i];
                break;
            }
        }
        return res;
    }
};
*/

