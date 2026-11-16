class Solution {
public:
    void dfs(vector<vector<int>>& rooms , int node,vector<int> &isvis){
        isvis[node] = 1;
        for(int i=0;i<rooms[node].size();i++){
            int neigh = rooms[node][i];
            if(isvis[neigh]==0) dfs(rooms,neigh,isvis);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> isvis(n,0);
        dfs(rooms,0,isvis);
        for(int i=0;i<n;i++){
            if(isvis[i]==0) return false;

        }
        return true;
    }
};