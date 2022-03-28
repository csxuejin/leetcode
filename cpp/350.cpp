class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        map<int, int> mm;
        for (int i=0; i<nums1.size(); i++){
            mm[nums1[i]]++;
        }
        for(int i=0; i<nums2.size(); i++){
            if(mm[nums2[i]] > 0){
                res.push_back(nums2[i]);
                mm[nums2[i]]--;
            }  
        }
        return res;
    }
};