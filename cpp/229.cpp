class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int a, b, cnt1, cnt2;
        cnt1 = cnt2 = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==a){
                cnt1++;
            }else if(nums[i]==b){
                cnt2++;
            }else if(cnt1==0){
                a = nums[i];
                cnt1=1;
            }else if(cnt2==0){
                b = nums[i];
                cnt2++;
            }else{
                cnt1--;
                cnt2--;
            }
        }
        cnt1= cnt2 = 0;
        for(auto it:nums){
            if(it==a) cnt1++;
            else if(it==b)cnt2++;
        }
        vector<int> res;
        cout<<"cnt1="<<cnt1<<" cnt2="<<cnt2<<endl;
        if(cnt1>nums.size()/3) res.push_back(a);
        if(cnt2>nums.size()/3) res.push_back(b);
        return res;
    }
};