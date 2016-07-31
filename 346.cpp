class MovingAverage {
private:
    queue<int> que;
    double res;
    int cnt;
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        res = 0;
        cnt = size;
    }
    
    double next(int val) {
        if(que.size()<cnt){
            que.push(val);
            res += val;
        }else{
            res -= que.front();
            res += val;
            que.pop();
            que.push(val);
        }
        
        return res/que.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */