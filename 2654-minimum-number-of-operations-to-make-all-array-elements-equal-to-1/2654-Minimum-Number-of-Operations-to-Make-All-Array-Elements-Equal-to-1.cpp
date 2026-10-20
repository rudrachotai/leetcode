class Solution {
public:
    int minOperations(vector<int>& nums) {
        int count1 = 0;
        int n = nums.size();
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1) count1++;
        }
        if(count1!=0) return (nums.size()-count1);
        
        int minop = INT_MAX ;
        for(int i=0;i<nums.size()-1;i++){
            int op = 0;
            int gcdofno = 0;
            for(int j = i+1;j<nums.size();j++){
               if(gcdofno==0) gcdofno = gcd(nums[i],nums[j]);
               else gcdofno = gcd(nums[j],gcdofno);
               if(gcdofno==1) {
               minop = min(minop,n-1+j-i);
               break;
               }

            }
        }
      if(minop==INT_MAX) return -1;
       return minop;
    }
};