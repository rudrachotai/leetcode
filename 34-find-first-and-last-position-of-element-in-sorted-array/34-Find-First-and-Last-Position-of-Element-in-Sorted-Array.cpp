class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector <int> ans = {-1,-1} ;
        int n = nums.size();
        int st = 0;
        int end = n-1;
        int mid = st + (end - st)/2;
        //first occurence
        while(st<=end){
            mid = st + (end - st)/2;
            if(nums[mid]==target){
                ans[0] = mid;
                end = mid-1;
            }
            else if(nums[mid]<target){
             st = mid+1;
            }
            else{
                end = mid-1;
            }
        }
        //last occurence
        st=0,end=n-1;
        while(st<=end){
            mid = st+(end-st)/2;
            if(nums[mid]==target){
                ans[1] = mid;
                st = mid+1;
            }
            else if(nums[mid]<target){
             st = mid+1;
            }
            else{
                end = mid-1;
            }
        }
        return ans;
    }
};