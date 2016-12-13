class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int j=0, res=0;
        for(int i=0; i<g.size() && j<s.size(); i++){
            while(s[j]<g[i] && j<s.size()){
                j++;
            }
            if(j<s.size()){
                res++;
                j++;
            }else{
                break;
            }
        }
        return res;
    }
};

