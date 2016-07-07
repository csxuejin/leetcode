class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, int> mm;
        for (int i=0; i<nums.size(); i++){
           if(mm.find(nums[i]) != mm.end()){
               if(i-mm[nums[i]]<=k){
                   return true;
               }
           }
           mm[nums[i]] = i;
        }
        return false;
    }
};