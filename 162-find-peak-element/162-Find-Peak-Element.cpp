class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int st = 0;
        int end = n-1;
        int mid = st + (end-st)/2;
        int result=0;
        while(st<=end){
           mid = st + (end-st)/2;
           if(mid<n-1 && nums[mid]<nums[mid+1] ){
               st=mid+1;
           }
           else{
               if(mid>=1 && nums[mid]>nums[mid-1]) return mid;
               result= mid;
               end = mid-1;
               
           }
        }
        return result;
    }
};