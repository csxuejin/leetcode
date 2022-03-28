class Solution {
public:
    static bool cmp(string a, string b){
        return a+b>b+a;
    }
 
    string largestNumber(vector<int>& nums) {
        vector<string> vec;
        for(int i=0; i<nums.size(); i++){
            vec.push_back(to_string(nums[i]));
        }
        sort(vec.begin(), vec.end(), cmp);
        string str = "";
        for(int i=0; i<vec.size(); i++){
            str += vec[i];
        }
        int i=0;
        while(str[i]=='0' && i<str.size()-1){
            i++;
        }
        str = str.substr(i);
        return str;
    }
};