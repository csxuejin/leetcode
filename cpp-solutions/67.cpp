class Solution {
public:
    string addBinary(string a, string b) {
        int t, last=0;
        string str = "";
        for(int i=a.size()-1, j=b.size()-1; i>=0 || j>=0; i--,j--){
            t = (i<0? 0:a[i]-'0') + (j<0? 0:b[j]-'0') + last; 
            str += (t%2)+'0';
            last = t/2;
        }
        if(last!=0){
            str += last + '0';
        }       
        reverse(str.begin(), str.end());
        return str;
    }
};

