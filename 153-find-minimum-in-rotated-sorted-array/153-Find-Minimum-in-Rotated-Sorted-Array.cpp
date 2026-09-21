class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int st = 0;
        int end = n-1;
        int guess = st + (end-st)/2;
        int result = nums[0];
        while(st<=end){
            guess = st + (end-st)/2;
            if(  nums[guess]>nums[end]){
                st = guess + 1;
            }
            else {
                result =min(result,nums[guess]);
                end = guess - 1;
            }
        }
        return result;
    }
};