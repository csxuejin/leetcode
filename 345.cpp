// method 1: flag the positon vowels exist
/*
class Solution {
public:
    string reverseVowels(string s) {
        string vowString = "aeiouAEIOU";
        vector<char> vec;
        vector<int> flag(s.size(), 0);
        for (int i=0; i<s.size(); i++){
           if (vowString.find(s[i]) != string::npos){
               flag[i] = 1;
               vec.push_back(s[i]);
           }
        }
        int index = vec.size()-1;
        for (int i=0; i<s.size(); i++){
            if(flag[i]){
                s[i] = vec[index--];
            }
        }
        return s;
        
    }
};
*/

// method 2: using 2 pointers
class Solution {
public:
    string reverseVowels(string s) {
        string::iterator p1=s.begin(), p2=s.end();
        // in c++ 11, can use "auto", like:
        // auto p1 = s.being(), p2 = s.end()
		string vowString = "aeiouAEIOU";
		while(p1<p2){
			while( vowString.find(*p1)==string::npos && (p1<p2)) p1++;
			while( vowString.find(*p2)==string::npos && (p1<p2)) p2--;
			if (p1<p2) swap(*p1,*p2);
			p1++;
			p2--;
		}
		return s;
    }
};
