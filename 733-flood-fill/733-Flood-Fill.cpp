class Solution {
public: 
   vector<int> x = {-1,1,0,0};
   vector<int> y = {0,0,-1,1};
   bool valid(int i,int j,int row,int col){
    if(i<0||i>=row||j<0||j>=col) return false;
    return true;
   }
    void dfs(vector<vector<int>>& image,int i,int j,int node,int color){
       
        image[i][j] = color;
        for(int k=0;k<4;k++){
            int row = i+x[k];
            int col = j+y[k];
            if(valid(row,col,image.size(),image[0].size())&&image[row][col]==node){
                dfs(image,row,col,node,color);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
       
        int node = image[sr][sc];
        if(node==color) return image;
        dfs(image,sr,sc,node,color);
        return image;
    }
};