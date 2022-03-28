// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int res = 0;
        int cnt = n/4;
        while(res < n){
            int t = read4(buf);
            if (t==4){
                res += t;
                buf += 4;
            }else{
                res += t;
                break;
            }
        }
        return res>n? n:res;
    }
};