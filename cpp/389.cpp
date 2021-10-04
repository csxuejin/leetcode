class Solution {
public:
    char findTheDifference(string s, string t) {
        char c = 0;
        for (char tmp:s){
            c = c^tmp;
        }
        for (char tmp:t){
            c = c^tmp;
        }
        return c;
    }
};