// method 1: using the lib
// class Solution {
// public:
//     string reverseString(string s) {
//         reverse(s.begin(), s.end());
//         return s;
//     }
// };

// method 2: replace one by one
class Solution {
public:
    string reverseString(string s) {
       int len = s.length();
       for(int i=0, j=len-1; i<j; i++,j--){
           char t = s[i];
           s[i] = s[j];
           s[j] = t;
       }
       return s;
    }
};