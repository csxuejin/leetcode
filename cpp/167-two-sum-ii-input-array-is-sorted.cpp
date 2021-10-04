class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        for(int l=0, r=numbers.size()-1; l<r; ){
            int val = numbers[l] + numbers[r];
            if(val == target){
                res.push_back(l+1);
                res.push_back(r+1);
                break;
            }else if(val>target){
                r--;
            }else{
                l++;
            }
        }
        
        return res;
    }
};