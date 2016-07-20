class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& pre) {
        vector<bool> visited(numCourses, false), onPath(numCourses, false);
        vector< vector<int> > road(numCourses);
        for(int i=0; i<pre.size(); i++){
            road[pre[i].second].push_back(pre[i].first);
        }
        
        for(int i=0; i<numCourses; i++){
            if(!visited[i] && isCircle(road, visited, onPath, i)){
                return false;
            }
        }
        return true;
    }
    
    bool isCircle(vector<vector<int>> &road, vector<bool> &visited, vector<bool> &onPath, int nodeId){
        if(visited[nodeId]){
            return false;
        }
        visited[nodeId] = onPath[nodeId] = true;
        for(int i=0; i<road[nodeId].size(); i++){
            int id = road[nodeId][i];
            if(onPath[id] || isCircle(road, visited, onPath, id)){
                return true;
            }
        }
        onPath[nodeId] = false;
        return false;
    }
};