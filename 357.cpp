class Solution {
private:
    long maxNum;
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n > 10){
            return countNumbersWithUniqueDigits(10);
        }
        maxNum = pow(10,n);
        bool used[10];
        
        int count = 1;
        for (int i=1; i<10; i++){
            used[i] = true;
            count += search(i, used);
            used[i] = false;
        }
        return count;
    }
    
    int search(long pre, bool used[]){
        int count = 0;
        if(pre < maxNum){
            count++;
        }else{
            return count;
        }
        
        for(int i=0; i<10; i++){
            if(!used[i]){
                used[i] = true;
                long cur = 10 * pre + i;
                count += search(cur, used);
                used[i] = false;
            }
        }
        return count;
    }
};