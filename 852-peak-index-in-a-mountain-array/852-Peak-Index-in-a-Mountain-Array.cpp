class Solution {
public:
    int peakIndexInMountainArray(vector<int>& nums) {
       int n = nums.size();
       int st = 0;
       int end = n-1;
       int mid = st + (end-st)/2;
       while(st<=end){
         mid = st + (end-st)/2;
         if( mid>=1 && mid<n && nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]){
            return mid;
         }
         else if( mid >=1 && mid<n && nums[mid]>nums[mid+1] && nums[mid]<nums[mid-1]){
            end = mid-1;
         }
         else {
            st = mid+1;
         }
       } 
       return mid;
    }
};