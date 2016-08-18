class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
       set<int> s(nums1.begin(), nums1.end());
       vector<int> vec;
       for (int i=0; i<nums2.size(); i++){
           if(s.count(nums2[i]) != 0){
               vec.push_back(nums2[i]);
               s.erase(nums2[i]);
           }
       }
       return vec;
    }
};
