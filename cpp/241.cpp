class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> res;
        for(int i=0; i<input.size(); i++){
            char ch = input[i];
            if(ch=='+' || ch=='-' || ch=='*'){
                vector<int> left = diffWaysToCompute(input.substr(0,i));
                vector<int> right = diffWaysToCompute(input.substr(i+1));
                for(int j=0; j<left.size(); j++){
                    for(int t=0; t<right.size(); t++){
                        switch (ch){
                            case '+':
                                res.push_back(left[j]+right[t]);
                                break;
                            case '-':
                                res.push_back(left[j]-right[t]);
                                break;
                            default:
                                res.push_back(left[j]*right[t]);
                        }
                    }
                }
            }
        }
        if(res.empty()){
            res.push_back(atoi(input.c_str()));
        }
        return res;
    }
};