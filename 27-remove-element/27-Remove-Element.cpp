class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i=0;
        int j = nums.size()-1;
        int no = nums.size();
        for(int k=0;k<nums.size();k++){
         if(nums[k]==val) no--;
        }
        while(i<j){
            if(nums[j]==val){
                j--;
                continue;
            }
            if(nums[i]==val&&nums[j]!=val){
                swap(nums[i],nums[j]);
                i++;
                j--;
            }
            if(nums[i]!=val) i++;
        }
        return no;
    }
};