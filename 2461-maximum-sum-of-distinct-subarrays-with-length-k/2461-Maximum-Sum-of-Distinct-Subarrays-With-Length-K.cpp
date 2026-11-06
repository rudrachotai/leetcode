class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        int n = nums.size();
        long long sum = 0;
        long long res = 0;

        int low = 0;
        int hi = k-1;
        for(int i=0;i<k;i++){
            map[nums[i]]++;
            sum+=nums[i];
        }
        if(map.size()==k)res = sum;
        for(hi=k;hi<nums.size();hi++){
            sum-=nums[low];
            map[nums[low]]--;
            if(map[nums[low]]==0) map.erase(nums[low]);
            low++;
            sum+=nums[hi];
            map[nums[hi]]++;
            if(map.size()==k) res = max(res,sum);
        }
        return res;
    }
};