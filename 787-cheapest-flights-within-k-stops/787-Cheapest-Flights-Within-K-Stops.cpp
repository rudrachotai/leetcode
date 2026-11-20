class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<vector<int>>> adj(n);
        queue<pair<int, int>> pq;
        vector<int> res(n,INT_MAX);
        for(int i=0;i<flights.size();i++){
            int src = flights[i][0];
            int dest = flights[i][1];
            int weight = flights[i][2];
            adj[src].push_back({dest,weight});
        }
        pq.push({0,src});
        res[src] = 0;
        int nodes = 0;
        while(pq.size()!=0&&nodes<=k){
            int sz = pq.size();
            while(sz--){int node = pq.front().second;
            int price = pq.front().first;
            pq.pop();
            
            
            for(int i=0;i<adj[node].size();i++){
                int neigh = adj[node][i][0];
                int p = price + adj[node][i][1];
                
                if(p<res[neigh]){
                   res[neigh] = p;
                   pq.push({p,neigh});
                }
            }}
            nodes++;
        }
        if(res[dst] == INT_MAX) return -1;
        return res[dst];
    }
};