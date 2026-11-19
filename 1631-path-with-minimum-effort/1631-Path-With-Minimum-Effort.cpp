class Solution {
public:
    bool isvalid(int r,int c,int row,int col){
        if(r<0||r>=row||c<0||c>=col) return false;
        return true;
    }
    int abs(int x,int y){
        if(x>y) return x-y;
        return y-x;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int row = heights.size();
        int col = heights[0].size();
        vector<vector<int>> res(row);
        for(int i=0;i<row;i++){
            vector<int> m(col,INT_MAX);
            res[i] = m;
        }
        priority_queue<pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>
        > pq;
        pq.push({0,{0,0}});
        res[0][0] = 0;
        vector<int> x = {0,0,-1,1};
        vector<int> y = {-1,1,0,0};
        while(pq.size()!=0){
            pair<int,pair<int,int>> p = pq.top();
            pq.pop();
            int dist = p.first;
            int r = p.second.first;
            int c = p.second.second;
            if(dist>res[r][c]) continue;
            for(int i=0;i<4;i++){
                int r1 = r+x[i];
                int c1 = c+y[i];
                if(!isvalid(r1,c1,row,col)) continue;
                int absdiff = max(dist,abs(heights[r][c],heights[r1][c1]));
                if(absdiff<res[r1][c1]){
                    res[r1][c1] = absdiff;
                    pq.push({absdiff,{r1,c1}});
                }
            }
        }
        return res[row-1][col-1];
    }
};