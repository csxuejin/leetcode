/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        vector<int> result;
        for(auto it : nestedList){
            dfs(it, result, 0);
        }
        int res = 0;
        for(int i=result.size()-1,level=1; i>=0; i--,level++){
            res += result[i]*level;
        }
        return res;
    }
    
    void dfs(NestedInteger& it, vector<int>&result, int dep){
        if(result.size() < dep+1){
            result.resize(dep+1);
        }
        if(it.isInteger()){
            result[dep] += it.getInteger();
        }else{
            for(auto t : it.getList()){
                dfs(t, result, dep+1);
            }
        }
    }
    
};



