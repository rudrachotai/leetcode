class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int st = 0;
        int end = matrix.size()-1;
        int mid = st + (end-st)/2;
        int result ;
        while(st<=end){
            mid = st + (end-st)/2;
            if(matrix[mid][0]<=target) {
                result=mid;
                st=mid+1;
            }else{
                end=mid-1;
            }
        }
        st = 0;
        end = matrix[0].size()-1;
        while(st<=end){
            mid = st + (end-st)/2;
            if(matrix[result][mid]==target) return true;
            else if(matrix[result][mid]<=target) st = mid+1;
            else end = mid-1;
        }
        return false;
    }
};