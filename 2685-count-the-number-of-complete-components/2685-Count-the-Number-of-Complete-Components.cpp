class Solution {
public:
    void dfs(vector<vector<int>> &adj,int node,int &nodes,vector<int> &isvis,int &edges){
       isvis[node] = 1;
       nodes++;
       edges+=adj[node].size();
       for(int i=0;i<adj[node].size();i++){
        int neigh = adj[node][i];
        if(isvis[neigh]==0) dfs(adj,neigh,nodes,isvis,edges);
       }
      
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(int i=0;i<edges.size();i++){
            int src = edges[i][0];
            int dest = edges[i][1];
            adj[src].push_back(dest);
            adj[dest].push_back(src);
        }
        vector<int> isvis(n,0);
        int count = 0;
        for(int i=0;i<n;i++){
            if(isvis[i]==0){ 
            int nodes = 0;
            int edges = 0;
            dfs(adj,i,nodes,isvis,edges);
            if((nodes*(nodes-1))==edges)count++;
            }
        }
          return count;
    }
};