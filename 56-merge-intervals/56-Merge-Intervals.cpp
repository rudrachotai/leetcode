class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
    if (intervals.empty()) return {};
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> ans;
    int start1 = intervals[0][0];
    int end1 = intervals[0][1];
    
    // A single loop is all you need when the input is pre-sorted
    for (int i = 1; i < intervals.size(); i++) {
        int start2 = intervals[i][0];
        int end2 = intervals[i][1];
        
        if (end1 >= start2) {
            end1 = max(end1, end2); // Merge intervals
        } else {
            ans.push_back({start1, end1}); // Save merged interval
            start1 = start2;               // Move to next interval
            end1 = end2;
        }
    }
    
    // Push the final tracked interval
    ans.push_back({start1, end1});
    return ans;
}

};