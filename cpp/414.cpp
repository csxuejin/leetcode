class Solution {
public:
    int thirdMax(vector<int>& nums) {
       set<int> ss;
       for(int i=0; i<nums.size(); i++){
           ss.insert(nums[i]);
           if(ss.size()>3)
               ss.erase(ss.begin());
       }
       return ss.size()<3? *ss.rbegin():*ss.begin();
    }
};
