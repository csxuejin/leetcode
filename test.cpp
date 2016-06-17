#include <iostream>
#include <string>
#include <sstream>
using namespace std;

void reverseWords(string &s) {
    istringstream is(s);
    string tmp;
    is >> s;
    while(is >> tmp){
    	cout<<"s = "<<s<<endl;
    	s = tmp + " " + s;
    	cout<<"now s = "<<s<<endl;
    } 
    if(s[0] == ' ') s = "";
}

int main(){
	string str = "this is a word";
	reverseWords(str);
	cout<<str<<endl;
	return 0;
}

