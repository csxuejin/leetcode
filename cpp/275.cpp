class Solution {
public:
    int hIndex(vector<int>& citations) {
        int l=0;
        int n = citations.size();
        int r = n-1;
        while(l<=r){
            int m = (l+r)/2;
            if(n-m>citations[m]){
                l = m+1;
            }else if(n-m<citations[m]){
                r = m-1;
            }else{
                return n-m;
            }
        }
        return n-l;
    }
};