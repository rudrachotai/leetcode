class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int st = 0;
        int end = (matrix.size()*matrix[0].size())-1;
        int mid = st + (end - st)/2;
        while(st<=end){
            mid = st + (end - st)/2;
            int row = mid/(matrix[0].size());
            int col = mid%(matrix[0].size());
            if(matrix[row][col]==target) return true;
            else if(matrix[row][col]<target) st = mid+1;
            else end = mid - 1;
        }
        return false;
    }
};