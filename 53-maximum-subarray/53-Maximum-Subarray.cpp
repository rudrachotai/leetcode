class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int bestend=nums[0];
        int result=nums[0];
        for(int i=1;i<nums.size();i++){
            bestend = max(bestend+nums[i],nums[i]);
            result = max(bestend,result);
        }
          return result;
    }

};