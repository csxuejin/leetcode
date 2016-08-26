class Codec {
private:
    vector<int> vec;
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string res = "";
        for(int i=0; i<strs.size(); i++){
            res += strs[i];
            vec.push_back(strs[i].size());
        }
        return res;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> res;
        for(int i=0,j=0; i<vec.size(); i++){
            res.push_back(s.substr(j,vec[i]));
            j += vec[i];
        }
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));