class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        vector<vector<string>> res;
        map<string, int> mm;
        for(int i=0; i<strings.size(); i++){
            string str = strings[i];
            int step = str[0]-'a';
            for(int j=0; j<str.size(); j++){
                if(str[j]-'a' >= step){
                    str[j] = str[j] - step;
                }else{
                    str[j] = 'z' - (step - (str[j]-'a' + 1));  
                }
            }
            if(mm.find(str)!=mm.end()){
                res[mm[str]].push_back(strings[i]);
            }else{
                res.push_back(vector<string>(1,strings[i]));
                mm[str] = res.size()-1;
            }
        }
        return res;
    }
};