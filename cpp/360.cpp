// method 2: 利用函数图像。
// 如果a>0, 那么就是一个开口向上的抛物线，最大值必然在两端；
// 如果a<0, 那么就是一个开口向下的抛物线，最小值必然是在两端。
class Solution{
    public:
        int sum(int &num, int &a, int &b, int &c){
            return a*pow(num,2) + b*num + c;
        }
        vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c){
            vector<int> res(nums.size(), 0);
            if(nums.empty()) return res;
            int i=0, j=nums.size()-1;
            if(a>0){
                int index = nums.size()-1;
                while(i<=j){
                    int ta = sum(nums[i], a, b, c);
                    int tb = sum(nums[j], a, b, c);
                    if(ta > tb){
                        res[index--] = ta;
                        i++;
                    }else{
                        res[index--] = tb;
                        j--;
                    }
                }
            }else{
                int index = 0;
                while(i<=j){
                    int ta = sum(nums[i], a, b, c);
                    int tb = sum(nums[j], a, b, c);
                    if(ta<tb){
                        res[index++] = ta;
                        i++;
                    }else{
                        res[index++] = tb;
                        j--;
                    }
                }
            }
            return res;
        }
};

// method 1: use priority_queue. The complexity is O(nlog(n));
/*
class Solution {
public:
    int sum(int &num, int &a, int&b, int &c){
        return a*pow(num,2) + b*num + c;
    }
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        priority_queue<int, vector<int>, greater<int>> que;
        for(int i=0; i<nums.size(); i++){
            que.push(sum(nums[i],a,b,c));
        }
        for(int i=0; i<nums.size(); i++){
            nums[i] = que.top();
            que.pop();
        }
        return nums;
    }
};
*/