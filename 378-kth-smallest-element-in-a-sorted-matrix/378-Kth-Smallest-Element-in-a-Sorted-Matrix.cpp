class Solution {
public:
    int helper(vector<vector<int>>& matrix,int target){
        int row = matrix.size()-1;
        int col = 0;
        int count = 0;
        while(row>=0 && col<matrix.size()){
          if(matrix[row][col]<=target){
            col++;
            count+=(row+1);
          }
          else row--;
        }
        return count;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
      int n = matrix.size();
      int st = matrix[0][0];
      int end = matrix[n-1][n-1];
      int mid = st + (end-st)/2;
      int result;
      while(st<=end){
      mid = st + (end-st)/2;
      int ans = helper(matrix,mid);
      if(ans<k) st = mid+1;
      else {
        result = mid;
        end = mid-1;
      }
      }
      return result;  
    }
};