// The question is unclear. It's useless.
/*
A word is abbreviation unique in a list if and only if one of the two cases is true:
1. The word is in the dictionary, then there should be no other word with the same abbr
2. If the word is not in the dictionary, then the dictionary should have no word with the given word’s abbr
*/
class ValidWordAbbr {
private:
    map<string, int> mm;
    map<string, int> inDic;
public:
    string change(string str){
        return str[0] + to_string(str.size()-2) + str.back();
    }

    ValidWordAbbr(vector<string> &dictionary) {
        for(int i=0; i<dictionary.size(); i++){
            string str = dictionary[i];
            inDic[str]=1;
            if(str.size()<=2){
                mm[str] = 1;
            }else{
                mm[change(dictionary[i])]++;
            }
        }
    }

    bool isUnique(string word) {
        string str = word.size()<2? word:change(word);
        return !mm[str] || mm[str]==1 && inDic[word];
    }
};


// Your ValidWordAbbr object will be instantiated and called as such:
// ValidWordAbbr vwa(dictionary);
// vwa.isUnique("hello");
// vwa.isUnique("anotherWord");