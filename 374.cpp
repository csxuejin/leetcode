// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        long long  left = 1;
        long long  right = n;
        while(left < right){
            long long mid = (left+right)/2;
            switch(guess(mid)){
                case 0:
                   return mid;
                case 1:
                   left = mid +1;
                   break;
                default:
                   right = mid -1;
                   break;
            }
        }
        return left;
    }
};