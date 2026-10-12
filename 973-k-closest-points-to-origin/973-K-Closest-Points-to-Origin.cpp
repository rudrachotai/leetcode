class Solution {
public:
    struct cmp{
     bool operator()(pair <int,int> &a,pair <int,int> &b){
         if(a.first!=b.first){
             return a.first<b.first;
         }
         return a.second<b.second;
     }  
    };
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> mmheap;
         vector<vector<int>> result;
        for(int i=0;i<k;i++){
            vector <int> point = points[i];
            int dist = (point[0]*point[0]+point[1]*point[1]);
            pair<int,int> p1 = {dist,i};
            mmheap.push(p1);
        }
        for(int i = k;i<points.size();i++){
            vector <int> point = points[i];
            int dist = (point[0]*point[0]+point[1]*point[1]);
            pair<int,int> p1 = {dist,i};
            mmheap.push(p1);
            if(mmheap.size()>k) mmheap.pop();
        }
        while(mmheap.size()!=0){
            result.push_back(points[mmheap.top().second]);
            mmheap.pop();
        }
        return result;
    }
};