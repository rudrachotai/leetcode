class Solution {
public:
    bool isvalid(int i,int j,int n,int m){
        if(i<0||i>=n||j<0||j>=m) return false;
        return true;
    }
    int orangesRotting(vector<vector<int>>& grid) {
       int n = grid.size();
       int m = grid[0].size();
       int fresh = 0;
       int time = 0;
       vector<int> x = {0,0,-1,1};
       vector<int> y = {1,-1,0,0};
       queue<pair<int,int>> q;
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==2){
                q.push({i,j});
                grid[i][j]=0;
            }
            else if(grid[i][j]==1) fresh++;
        }
       }
       while(q.size()!=0 && fresh>0){
        time++;
        int k = q.size();
        for(int i=0;i<k;i++){
            pair<int,int> p = q.front();
            q.pop();
          for(int r=0;r<4;r++) {
             int row = p.first + x[r];
            int col = p.second + y[r];
            if(isvalid(row,col,n,m)&&grid[row][col]==1){
                q.push({row,col});
                grid[row][col] = 0;
                fresh--;
            }}
        }
       }
       if(fresh>0) return -1;
       return time;
    }
};