class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int nodeletionend=arr[0];
        int onedeletionend=INT_MIN;
        int result = arr[0];
        for(int i=1;i<arr.size();i++){
            int lastnodeletionend = nodeletionend;
            nodeletionend = max(nodeletionend+arr[i],arr[i]);
            int v1= onedeletionend;
            if(onedeletionend==INT_MIN){
                v1=arr[i];
            }
            else v1+=arr[i];
            onedeletionend = max(v1,lastnodeletionend);
            result = max(result,max(nodeletionend,onedeletionend));

        }
        return result;
    }
};