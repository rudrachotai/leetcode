class Solution {
public:
    void dfs(vector<vector<int>> &adj,int node,vector<int> &vis){
        vis[node] = 1;
        for(int i=0;i<adj[node].size();i++){
            int neigh = adj[node][i];
            if(vis[neigh]==0) dfs(adj,neigh,vis);
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        for(int i=0;i<edges.size();i++){
            int src = edges[i][0];
            int dest = edges[i][1];
            adj[src].push_back(dest);
            adj[dest].push_back(src);
        }
        vector<int> vis(n,0);
        dfs(adj,source,vis);
        if(vis[destination]==0) return false;
        return true;
    }
};