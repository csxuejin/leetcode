class Solution {
public:
    string convertToTitle(int n) {
        string str = "";
        while(n){
            n--;
            str = (char)(n%26+'A') + str;
            n /= 26;
        }
        return str;
    }
};


