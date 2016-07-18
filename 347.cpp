class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> mm;
        for (int i=0; i<nums.size(); i++){
            mm[nums[i]] ++;
        } 
        map<int, vector<int>> freMap;
        for(map<int,int>::iterator tmp=mm.begin(); tmp!=mm.end(); tmp++){
            freMap[tmp->second].push_back(tmp->first);
        }
        
        vector<int> res;
        for(map<int,vector<int>>::reverse_iterator  it=freMap.rbegin(); it!=freMap.rend(); it++){
            for(int j=0; j<it->second.size(); j++){
                if(res.size()>=k) return res;
                res.push_back(it->second[j]);
            }
        }
        return res;
    }
};