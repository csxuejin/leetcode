class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int last = 0;
        if(digits.empty()) return digits;
        digits.back()++;
        for(int i=digits.size()-1; i>=0;  i--){
            int t = digits[i] + last;
            digits[i] = t%10;
            last = t/10;
        }
        if(last){
            digits.insert(digits.begin(), last);
        }
        return digits;
    }
};