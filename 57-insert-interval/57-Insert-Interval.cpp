class Solution {
public:
    vector<vector<int>> mergeintervals(vector<vector<int>>& intervals){
        if (intervals.empty()) return {};
        vector<vector<int>> ans;
        int start1=intervals[0][0];
        int end1=intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            int start2 = intervals[i][0];
            int end2 = intervals[i][1];
            if(end1>=start2){
                end1=max(end1,end2);
            }
            else{
              ans.push_back({start1,end1});
              start1=start2;
              end1=end2;

            }
        }
        ans.push_back({start1,end1});
        return ans;
    }
 
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
       int idx = intervals.size();
       for(int i=0;i<intervals.size();i++){
       if(intervals[i][0]>newInterval[0]){
        idx = i;
       break;
       } 
       }
       intervals.insert(intervals.begin()+idx,newInterval);
      vector<vector<int>> ans = mergeintervals(intervals);
       return ans;
    }
};