class NumArray {
private: 
    vector<int> vec;
public:
    NumArray(vector<int> &nums) {
        vec.push_back(0);
        for(int i=0; i<nums.size(); i++){
            if(i==0) vec.push_back(nums[0]);
            else
                vec.push_back(vec.back()+nums[i]);
        }
    }

    int sumRange(int i, int j) {
        return vec[j+1] - vec[i];
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);