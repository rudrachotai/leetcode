class Solution {
public:
    int findMaxLength(vector<int>& nums) {
     unordered_map <int,int> freq;
     int result = INT_MIN;
     int sum=0;
     int totalsum=0;
     
     for(int i=0;i<nums.size();i++){
        if(nums[i]==0) sum--;
        else sum++;
        totalsum+=nums[i];
        if(sum==0) result=max(i+1,result);
        else if(freq.find(sum)!=freq.end()){
            result=max(i-freq[sum],result);
        }
        else freq[sum]=i;
     }
     if(result==INT_MIN) return 0;
     return result;
       
    }
};