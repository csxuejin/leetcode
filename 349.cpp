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


/* method 2:
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> mm;
        map<int, int> record;
        vector<int> res;
        for(int i=0; i<nums1.size(); i++){
            mm[nums1[i]] = 1;
        }
        for(int i=0; i<nums2.size(); i++){
            if(mm[nums2[i]]==1){
                res.push_back(nums2[i]);
                mm[nums2[i]]--;
            }
        }
        return res;
    }
};
*/