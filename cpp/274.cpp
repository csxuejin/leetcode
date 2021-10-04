class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> res(n+1,0);
        for(int i=0; i<citations.size(); i++){
            if(citations[i]>=n){
                res[n]++;
            }else{
                res[citations[i]]++;
            }
        }
        int sum = 0;
        for(int i=n; i>=0; i--){
            sum += res[i];
            if(sum>=i){
                return i;
            }
        }
        return 0;
    }
};