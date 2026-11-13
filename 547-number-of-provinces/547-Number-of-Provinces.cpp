class Solution {
public:
    void dfs(int node,vector<vector<int>>& isConnected,vector<bool> &vis ){
     vis[node] = true;

     for(int i=0;i<isConnected[node].size();i++){
        
        if(vis[i]==0&&isConnected[node][i]==1){
            dfs(i,isConnected,vis);
        }
     }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int count = 0;
        vector<bool> vis(n,0);
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                dfs(i,isConnected,vis);
                count++;
            }
            
        }
        return count;
    }
};