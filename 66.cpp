class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if(digits.size() == 0) return digits;
        reverse(digits.begin(), digits.end());
        int last = (digits[0] + 1)/10;
        digits[0] = (digits[0] + 1) % 10;
        for (int i=1; i<digits.size(); i++){
            digits[i] += last;
            last = digits[i]/10;
            digits[i] %= 10;
        }
        if(last != 0){
            digits.push_back(last);
        }
        reverse(digits.begin(), digits.end());
        return digits;
    }
};