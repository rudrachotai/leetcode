class Solution {
public:
    int search(vector<int>& nums, int target) {
      int n = nums.size();
      int st = 0;
      int end = n-1; 
      int mid = st + (end-st)/2;
      int result = -1;
      while(st<=end){
        mid = st + (end-st)/2;
        if(nums[mid] == target ){
            result = mid;
            break;
        }
        else if(nums[mid]>nums[end]){
            if(nums[mid]<target) st = mid+1;
            else{
                if(nums[st]>target) st = mid+1;
                else end = mid-1;
            }
        }
        else{
            if(nums[mid]>target) end = mid-1;
            else{
                if(nums[end]>=target) st = mid+1;
                else end = mid-1;
            }
        }
        
      }
      return result;
    }
};