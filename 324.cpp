class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> vec = nums;
        sort(vec.begin(), vec.end());
        int j = vec.size()-1;
        for(int i=1; i<nums.size(); i+=2){
            nums[i] = vec[j--];
        }
        for(int i=0; i<nums.size(); i+=2){
            nums[i] = vec[j--];
        }
    }
};