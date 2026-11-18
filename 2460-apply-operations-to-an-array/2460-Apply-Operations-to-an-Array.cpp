class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int st = 0;
    int n = nums.size();
    
    for (int i = 0; i < n; i++) {
        if (i + 1 < n && nums[i] == nums[i + 1]) {
            if (nums[i] != 0) {
                nums[i] *= 2;
                swap(nums[i], nums[st++]);
            }
            nums[i + 1] = 0;
        } else if (nums[i] != 0) {
            swap(nums[i], nums[st++]);
        }
    }
    
    return nums;
    }
};