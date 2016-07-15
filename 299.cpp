class Solution {
public:
    string num2str(int num){
        if (num==0){
            return "0";
        }
        string str = "";
        while(num){
            str = (char)(num%10+'0')+str;
            num /= 10;
        }
        return str;
    }

    string getHint(string secret, string guess) {
        int bull=0;
        int cow=0;
        map<char, int> mm;
        for(int i=0; i<secret.size(); i++){
            if(secret[i] == guess[i]){
                bull++;
            }else{
                mm[secret[i]]++;
            }
        }
        for(int i=0; i<guess.size(); i++){
            if(guess[i]==secret[i]){
                continue;
            }
            if(mm[guess[i]]>0){
                cow++;
                mm[guess[i]]--;
            }
        }
        return  num2str(bull)+"A"+num2str(cow)+"B";
    }
};