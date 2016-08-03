class Solution {
public:
    const static string THOUS[];
    const static string HUNDS[];
    const static string TENS[];
    const static string ONES[];
    string intToRoman(int num) {
        string result;
        result += THOUS[(int)(num/1000)%10];
        result += HUNDS[(int)(num/100)%10];
        result += TENS[(int)(num/10)%10];
        result += ONES[num%10];
        return result;
    }
};

const string Solution::THOUS[]  = {"","M","MM","MMM"};
const string Solution::HUNDS[]  = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
const string Solution::TENS[]   = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
const string Solution::ONES[]   = {"","I","II","III","IV","V","VI","VII","VIII","IX"};