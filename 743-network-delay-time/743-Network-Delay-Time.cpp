class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<vector<int>>> adj(n);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> res(n,INT_MAX);
        for(int i=0;i<times.size();i++){
            int src = times[i][0]-1;
            int dest = times[i][1]-1;
            int weight = times[i][2];
            adj[src].push_back({dest,weight});
        }
        pq.push({0,k-1});
        res[k-1] = 0;
        while(pq.size()!=0){
            int node = pq.top().second;
            int weight = pq.top().first;
            pq.pop();
            if(weight>res[node]) continue;
            for(int i=0;i<adj[node].size();i++){
                int neigh = adj[node][i][0];
                int d = weight + adj[node][i][1];
                if(d>=res[neigh]) continue;
                else{
                     res[neigh] = d;
                     pq.push({d,neigh});
                }
            }
        }
        int mx =  INT_MIN;
        for(int i=0;i<n;i++){
            mx = max(mx,res[i]);
        }
        if(mx==INT_MAX) return -1;
        return mx;
    }
};