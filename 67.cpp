class Solution {
public:
    string addBinary(string a, string b) {
        vector<int> vec;
        int t, last=0;
        string str = "";
        for(int i=a.size()-1, j=b.size()-1; i>=0 || j>=0; i--,j--){
            t = (i<0? 0:a[i]-'0') + (j<0? 0:b[j]-'0') + last; 
            vec.push_back(t%2);
            last = t/2;
        }
        if(last!=0){
            vec.push_back(last);
        }       
        for(int i=vec.size()-1; i>=0; i--)  
            str += vec[i]+'0';
        return str;
    }
};
