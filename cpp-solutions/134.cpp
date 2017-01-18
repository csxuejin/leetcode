class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
         int sum = 0, tank = 0;        
         int start = 0;
         for(int i=0; i<gas.size(); i++){
             tank = tank + gas[i] - cost[i];
             sum = sum + gas[i] - cost[i];
             if(tank<0){
                 tank = 0;
                 start = i+1;
             }
         }
         return sum<0? -1:start;
    }
};

