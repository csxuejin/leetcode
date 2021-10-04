class Solution {
public:
    void helper(string str, vector<int> *vec){
        int ret = 0;
        for (int i=0; i<str.size(); i++ ){
            if (str[i] != '.')  
                ret = ret * 10 + (str[i]-'0');
            if (str[i] == '.' || i==str.size()-1){
                (*vec).push_back(ret);
                ret = 0;
            }
        }
    }

    int compareVersion(string version1, string version2) {
        vector<int> v1, v2;
        helper(version1, &v1);
        helper(version2, &v2);
        int i=0, j=0;
        for (; i<v1.size() || j<v2.size(); i++,j++){
            if ( (j>=v2.size() && v1[i]>0) || (i<v1.size() && j<v2.size() && v1[i] > v2[j])) return 1;
            if ( (i>=v1.size() && v2[j]>0) || (i<v1.size() && j<v2.size() && v1[i] < v2[j])) return -1;
        }
        return 0;
    }
};
