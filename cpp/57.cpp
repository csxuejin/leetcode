/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        int start = newInterval.start;
        int end = newInterval.end;
        vector<Interval> res;
        int i=0;
        bool flag = false;
        for(i=0; i<intervals.size(); i++){
            if(intervals[i].start>end) {
                if(!flag){
                    res.push_back(Interval(start, end));
                    flag = true;
                }
                res.push_back(intervals[i]);
            }
            if(intervals[i].end<start){
                res.push_back(intervals[i]);
            }else{
                start = min(intervals[i].start, start);
                end = max(intervals[i].end, end);
            }
        }
        if(!flag){
            res.push_back(Interval(start, end));
        }
       
        return res;            
    }
};

