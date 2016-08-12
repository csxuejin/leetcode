class Solution {
private:
    vector<int> res;
public:
    Solution(vector<int> nums) {
        res = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return res;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> vec(res);
        for(int i=0; i<vec.size(); i++){
            int pos = rand()%(vec.size()-i);
            swap(vec[pos+i], vec[i]);
        }
        return vec;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */
 