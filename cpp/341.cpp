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
class NestedIterator {
private:
    int cnt;
    queue<int> que;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        dfs(nestedList);
    }
    
    void dfs(vector<NestedInteger> &nestedList){
        for(auto it : nestedList){
            if(it.isInteger()){
                que.push(it.getInteger());
            }else{
                dfs(it.getList());
            }
        }
    }

    int next() {
        int t = que.front();
        que.pop();
        return t;
    }

    bool hasNext() {
        return !que.empty();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */