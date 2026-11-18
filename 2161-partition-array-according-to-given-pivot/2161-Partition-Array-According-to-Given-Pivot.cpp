class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int l = 0;
        int n=nums.size();
        vector<int> ans(nums.size());
        int hi = nums.size()-1;
        for(int i=0 ,j=n-1;i<nums.size();i++,j--){
            if(nums[i]<pivot){
                ans[l] = nums[i];
                l++;
            }
           if(nums[j]>pivot){
                ans[hi] = nums[j];
                hi--;
            }
        }
        while(l<=hi){
            ans[l] = pivot;
            l++;
        }
        return ans;
    }
};