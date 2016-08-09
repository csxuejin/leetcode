/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        if(points.size()<=1) return points.size();
        int res = INT_MIN;
        for(int i=0; i<points.size(); i++){
            int infiniteSlope = 0;
            int sameNode = 1;
            unordered_map<double, int> slope;
            for(int j=i+1; j<points.size(); j++){
                if(points[i].x == points[j].x && points[i].y==points[j].y){
                    sameNode++;
                }else if(points[i].x == points[j].x){
                    infiniteSlope++;
                }else{
                    slope[(double)(points[j].y-points[i].y)/(double)(points[j].x-points[i].x)]++;
                } 
            }
            int localMax INT_MIN;
            if(!slope.empty()){
              for(auto it:slope){
                localMax = max(localMax, it.second);
              }
              localMax = max(localMax, infiniteSlope);
              localMax += sameNode;
            }else{
              localMax = sameNode + infiniteSlope;
            }
            res = max(res, localMax);
        }
        return res;
    }
};
