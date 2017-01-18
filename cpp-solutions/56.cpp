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
    static bool cmp(Interval a, Interval b){
        return a.start < b.start;
    }
    vector<Interval> merge(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        vector<Interval> res;
        for(int i=0; i<intervals.size(); i++){
            if(res.empty()) res.push_back(intervals[i]);
            else{
                if(res.back().end>=intervals[i].start){
                    if(res.back().start==intervals[i].start && res.back().end==intervals[i].end) 
                        continue;
                    res.back().end = max(res.back().end, intervals[i].end);
                }else{
                    res.push_back(intervals[i]);
                }
            }
        }
        return res;
    }
};