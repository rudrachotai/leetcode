class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map <int,int> freq;
        int sum=0;
        int result = 0;
        freq[0]++;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(freq.find(sum-k)!=freq.end()){
                result+=freq[sum-k];
            }
            freq[sum]++;
        }
        return result;
    }
};