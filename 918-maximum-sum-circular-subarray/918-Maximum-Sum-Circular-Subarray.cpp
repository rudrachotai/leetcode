class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        //case 1 considering max result is in between and also find min result for case 2
        int resultmax = nums[0];
        int resultmin = nums[0];
        int minbest= nums[0];
        int maxbest = nums[0];
        
        int totalsum = nums[0];
        for(int i=1;i<nums.size();i++){
            minbest=min(minbest+nums[i],nums[i]);
            maxbest=max(maxbest+nums[i],nums[i]);
            totalsum+=nums[i];
            resultmax = max(resultmax,maxbest);
            resultmin = min(resultmin,minbest);
        }
        //case 2 is taken care here
        if(totalsum==resultmin) return resultmax;
        return max(resultmax,totalsum-resultmin);

    }
};