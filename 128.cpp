class Solution {
private:
    unordered_map<int, int> fa;
    int find(int x){
        if(fa[x]==x){
            return x;
        }else{
           fa[x] = find(fa[x]);
           return fa[x];
        }
    }
    
    void Union(int x, int y){
        int xroot = find(x);
        int yroot = find(y);
        fa[xroot] = yroot;
    }
public:
    int longestConsecutive(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++)
            fa[nums[i]] = nums[i];
        for(int i=0; i<nums.size(); i++){
            if(fa.find(nums[i]-1) != fa.end()){
                Union(nums[i]-1, nums[i]);
            }else if(fa.find(nums[i]+1) != fa.end()){
                Union(nums[i], nums[i]+1);
            }
        }
        int res = 0;
        unordered_map<int,int> cntNum;
        for(auto it:fa){
            int t = find(it.second);
            cntNum[t]++;
            res = max(res, cntNum[t]);
        }
        return res;
    }
};
