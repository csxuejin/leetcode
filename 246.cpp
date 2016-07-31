class Solution {
public:
    bool isStrobogrammatic(string num) {
        map<char, char> mm = {{'0','0'}, {'1','1'}, {'6','9'}, {'8','8'}, {'9','6'}};
        if(num.empty()) return true;
        if(num.size()==1)
            return num[0]=='0' || num[0]=='8' || num[0] == '1';
        int i,j;
        for(i=0, j=num.size()-1; i<j; i++,j--){
            if(mm.find(num[i])==mm.end() || mm.find(num[j])==mm.end()){
                cout<<"p1"<<endl;
                return false;
            }
            if(mm[num[i]] != num[j]){
                return false;
            }
        }
        if(i==j)
            return num[i]=='0' || num[i]=='8' || num[i] == '1';
        return true;
    }
};