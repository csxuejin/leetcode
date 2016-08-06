class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> sta;
        int lastMax = 0;
        int res = 0;
        for(int i=0; i<height.size(); i++){
            if(sta.empty()){
                if(height[i]!=0){
                    sta.push_back(height[i]);
                    lastMax = height[i];
                } 
            }else{
                if(height[i]>=lastMax){
                    while(!sta.empty()){
                        res += lastMax - sta.back();
                        sta.pop_back();
                    }
                    sta.push_back(height[i]);
                    lastMax = height[i];
                    continue;
                }
                if(height[i]<lastMax && height[i]>sta.back()){
                   for(int j=0; j<sta.size(); j++){
                       if(sta[j]<height[i]){
                           res += height[i]-sta[j];
                           
                           sta[j] = height[i];
                       }
                   }
                   sta.push_back(height[i]);
                   continue;
                }
                if(height[i]<=sta.back()){
                    sta.push_back(height[i]);
                }
            }
        }
        return res;
    }
};