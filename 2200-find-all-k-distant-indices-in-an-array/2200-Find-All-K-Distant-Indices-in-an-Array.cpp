class Solution {
public:
void atr(vector<int> &result ,int st,int end){
     for(int i=st;i<=end;i++){
        result.push_back(i);
     }
}
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
       vector<int> result;
       int n = nums.size();
       for(int i=0;i<nums.size();i++){
        if(nums[i]==key){
            int st = max(i-k,0);
            int end = min(i+k,n-1);
            if(result.size()!=0&&result[result.size()-1]>=st){
                st = result[result.size()-1] +1;
            }
            atr(result,st,end);
        }
       }
       return result;
    }
};