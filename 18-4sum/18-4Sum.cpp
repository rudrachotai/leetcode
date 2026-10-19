class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        int n = nums.size();
        if (n < 4) return result; 
        sort(nums.begin(),nums.end());
        for(int i = 0;i<nums.size()-3;i++){
            if(i!=0 && nums[i] == nums[i-1]) continue;
           for(int j = i+1  ; j<nums.size()-2;j++){
            if(j>i+1 && nums[j] == nums[j-1]) continue;
            int x = j+1;
            int y = n-1;
            while(x<y){
             long long sum = (long long)nums[x]+nums[y]+nums[i]+nums[j];
            if(sum==target){
               result.push_back({nums[i],nums[j],nums[x],nums[y]});
                x++;
                y--;
                while(x<n && nums[x] == nums[x-1]) x++;
                while(y>=0 && nums[y+1]==nums[y]) y--;
            }
            else if(sum<target){
                x++;
            }
            else y--;
            }
           }
        }
        return result;
    }
};