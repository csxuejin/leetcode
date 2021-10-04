class Solution {
private:
    map<int, bool> mm;
public:
    bool isHappy(int n) {
        if(mm[n]){
            return false;
        }
        mm[n] = true;
        int t = 0;
        while(n){
            t = t+ pow(n%10,2);
            n /= 10;
        }
        if(t==1) return true;
        return isHappy(t);
    }
};