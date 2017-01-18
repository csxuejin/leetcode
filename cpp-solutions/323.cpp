class Solution {
private:
    unordered_map<int,int> fa;
    
public:
    int findRoot(int x){
        if(fa[x]==x){
            return x;
        }else{
            fa[x] = findRoot(fa[x]);
            return fa[x];
        }
    }
    
    void unionRoot(int x, int y){
        int xroot = findRoot(x);
        int yroot = findRoot(y);
        if(xroot==yroot) return;
        fa[xroot] = yroot;
    }


    int countComponents(int n, vector<pair<int, int>>& edges) {
         for(int i=0; i<n; i++)
            fa[i] = i;
         for(int i=0; i<edges.size(); i++){
             unionRoot(edges[i].first, edges[i].second);
         }
         set<int> res;
         for(auto it:fa){
             int t = findRoot(it.second);
             res.insert(t);
         }
         return res.size();
    }
};

