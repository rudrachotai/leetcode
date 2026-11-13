class Solution {
public:
    int count = 0;
    vector<int> x = {0,0,-1,1};
    vector<int> y = {1,-1,0,0};
    bool isvalid(int i,int j,vector<vector<char>>& grid,vector<vector<bool>> &vis){
        int n = grid.size();
        int m = grid[0].size();
        if(i<0||i>=n||j<0||j>=m||vis[i][j]==1) return false;
        return true;
    }

    void dfs(int i,int j,vector<vector<char>>& grid,vector<vector<bool>> &vis){
        vis[i][j] = 1;
        for(int k=0;k<4;k++){
            int nr = i+x[k];
            int nc = j+y[k];
            if(isvalid(nr,nc,grid,vis)&&grid[nr][nc]=='1') dfs(nr,nc,grid,vis);
         }
        
    }
    int numIslands(vector<vector<char>>& grid) {
       int n = grid.size();
       int m = grid[0].size();
       vector<vector<bool>> visited(n);
       for(int i=0;i<n;i++){
        vector<bool> t(m,0);
        visited[i] = t;
       }
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='1'&&visited[i][j]==0){
                  dfs(i,j,grid,visited);
                  count++;
            }
        }
       } 
       return count;
    }
};