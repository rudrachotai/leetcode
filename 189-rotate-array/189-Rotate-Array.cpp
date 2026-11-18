class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if(n==0) return;
        k = k%n;
        reverse(nums.begin(),nums.begin()+ n - k);
        reverse(nums.begin(),nums.begin() + n);
        reverse(nums.begin(),nums.begin() + k);
    }
};