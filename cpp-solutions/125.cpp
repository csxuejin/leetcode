// o(log(n)) solution
class Solution {
public:
    bool isPalindrome(string s) {
        int l=0, r=s.size()-1;
        while(l<r){
            while(l<r && !isalnum(s[l])) l++;
            if(l>=r) break;
            s[l] = isalpha(s[l])? tolower(s[l]):s[l];
            
            while(l<r && !isalnum(s[r])) r--;
            if(l>=r) break;
            s[r] = isalpha(s[r])? tolower(s[r]):s[r];
            
            if(s[l]!=s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
};



// class Solution {
// public:
//     bool isPalindrome(string s) {
//         string str = "";
//         for (int i=0; i<s.size(); i++){
//             if(isalnum(s[i])){
//                 if (isalpha(s[i])){
//                    s[i] = tolower(s[i]);
//                 }
//                 str += s[i];
//             }
//         }
//         string tmp = str;
//         reverse(str.begin(), str.end());
//         return tmp == str;
//     }
// };