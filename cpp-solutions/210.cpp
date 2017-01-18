class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& pre) {
        vector<vector<int>> road(numCourses);
        for(int i=0; i<pre.size(); i++){
            road[pre[i].second].push_back(pre[i].first);
        }
        
        vector<bool> visited(numCourses, false), onPath(numCourses,false);
        vector<int> topoSort;
        for(int i=0; i<numCourses; i++){
            if(!visited[i] && isCircle(i,road, visited, onPath, topoSort)){
                return {};
            }
        }
        reverse(topoSort.begin(), topoSort.end());
        return topoSort;
    }
    
    bool isCircle(int nodeId, vector<vector<int>>&road, vector<bool> &visited, vector<bool> &onPath, vector<int>&topoSort){
        if(visited[nodeId]){
            return false;
        }
        
        visited[nodeId] = onPath[nodeId] = true;
        for(int i=0; i<road[nodeId].size(); i++){
            int id = road[nodeId][i];
            if(onPath[id] || isCircle(id, road, visited, onPath, topoSort)){
                return true;
            }
        }
        onPath[nodeId] = false;
        topoSort.push_back(nodeId);
        return false;
    }
};



