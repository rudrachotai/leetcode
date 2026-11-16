class Solution {
public:
    bool result = true;
    void dfs(vector<vector<int>>& graph,int node,int color,vector<int> &col){
        col[node] = color;
        for(int i=0;i<graph[node].size();i++){
            int neigh = graph[node][i];
            if(col[neigh]!=-1&&col[neigh]==color) result = false;
            if(col[neigh]==-1) dfs(graph,neigh,1-color,col);
        }
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> col(n,-1);
        for(int i=0;i<graph.size();i++){
            if(col[i]==-1) dfs(graph,i,0,col);
        }
        return result;
    }
};