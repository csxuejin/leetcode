class Solution {
private:
    unordered_map<int,int> fa;
    int findRoot(int x){
        if(fa[x] == x){
            return x;
        }else{
            fa[x] = findRoot(fa[x]);
            return fa[x];
        }
    }
    
    bool unionRoot(int x, int y){
        int xRoot = findRoot(x);
        int yRoot = findRoot(y);
        if(xRoot==yRoot) return false;
        fa[xRoot] = yRoot;
        return true;
    }
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        for(int i=0; i<n; i++)
            fa[i] = i;
        for(int i=0; i<edges.size(); i++){
            if(!unionRoot(edges[i].first, edges[i].second))
                return false;
        }
        set<int> ss;
        for(auto it:fa){
            ss.insert(findRoot(it.second));
        }
        return ss.size()==1;
    }
};


