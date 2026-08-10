class Solution {
public:
    int abs(int x){
        if(x<0) return -x;
        return x;
    }
    int maxAbsoluteSum(vector<int>& nums) {
        int minbest = nums[0];
        int maxbest = nums[0];

        int result = nums[0];
        if(result<0) result*=-1;
        for(int i=1;i<nums.size();i++){
            minbest = min(minbest+nums[i],nums[i]);
            maxbest = max(maxbest+nums[i],nums[i]);
            
            result = max(result,max(abs(minbest),abs(maxbest)));
        }
        
        return result;
    }
};