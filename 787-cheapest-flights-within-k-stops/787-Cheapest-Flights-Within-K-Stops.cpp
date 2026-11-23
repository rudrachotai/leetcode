class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int V = n;
        vector<int> ans(V,1e8);
        ans[src] = 0;
        for(int i=0;i<=k;i++){
            vector<int> temp = ans;
            for(int j=0;j<flights.size();j++){
                int s = flights[j][0];
                int d = flights[j][1];
                int w = flights[j][2];
                
                if(ans[s]!=1e8 && temp[d]>w+ans[s]){
                    temp[d] = w+ans[s];
                }
            }
            ans = temp;
        }
       if(ans[dst] == 1e8) return -1;

        return ans[dst];
    }
};