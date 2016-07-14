// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long left = 1, right = n;
        while(left < right){
            int mid = (left + right)/2;
            if(isBadVersion(mid)){
                if(!isBadVersion(mid-1)){
                    return mid;
                }
                right = mid -1; 
            }else{
                left = mid + 1;
            }
        }
        return isBadVersion(left)? left:right;
    }
};