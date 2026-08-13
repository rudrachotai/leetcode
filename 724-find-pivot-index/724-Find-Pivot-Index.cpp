class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int left = 0;
        int right = 0;
        int n=nums.size();
        for(int i=1;i<n;i++){
            right+=nums[i];
        }
        for(int i=0;i<n;i++){
         if(right==left) return i;
          if(i+1<n){ left+=nums[i];
            right-=nums[i+1];}
          
        }
        return -1;
    }
};