class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        vector<int> vec;
        while(x){
            vec.push_back(x%10);
            x /= 10;
        }
        for(int i=0, j=vec.size()-1; i<j; i++,j--){
            if(vec[i] != vec[j])
                return false;
        }
        return true;
    }
};