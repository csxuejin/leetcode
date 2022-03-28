class Solution {
private:
    vector<string> THOUS  = {"","M","MM","MMM"};
    vector<string> HUNDS  = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
    vector<string> TENS   = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
    vector<string> ONES   = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
    
public:
    string intToRoman(int num) {
        string result;
        result += THOUS[(int)(num/1000)%10];
        result += HUNDS[(int)(num/100)%10];
        result += TENS[(int)(num/10)%10];
        result += ONES[num%10];
        return result;
    }
};
