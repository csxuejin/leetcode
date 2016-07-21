class Solution {
public:
    vector<vector<int> > fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int i,j;    
        vector< vector<int> > result;
        int n=nums.size();
        for(i=0; i<n; i++){
            if(i>0 && nums[i]==nums[i-1])
                continue;
            for(j=i+1; j<n-2; j++){
                if(j>i+1 && nums[j]==nums[j-1])
                    continue;
                int left, right;            
                long long s = (nums[i]+nums[j]);
                left = j+1; 
                right = nums.size()-1;
                while(left<right){
                    int t = nums[left] + nums[right] + s;                
                    if(t == target){
                        while(left+1<n && nums[left]==nums[left+1]){
                            left++;
                        }
                        while(right-1>=0 && nums[right]==nums[right-1]){
                            right--;
                        }
                        result.push_back(vector<int>{nums[i], nums[j], nums[left], nums[right]});  
                        left++;
                        right--;
                    }else if(t>target){
                        right--;
                    }else{
                        left++;
                    }               
                }
            }
        }
        return result;        
    }
};