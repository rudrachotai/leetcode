class Solution {
public:
int find(int *arr,int n){
    int result=INT_MIN;
    for(int k=0;k<n;k++){
    result=max(result,arr[k]);
    }
    return result;
}
    int characterReplacement(string s, int k) {
        int result=INT_MIN;
        int i=0;
        int arr[26];
        for(int j=0;j<s.size();j++){
            arr[s[j]-65]++;
            int frq=find(arr,26);
            int diff= j-i+1-frq;
            while(diff>k){
                arr[s[i]-65]--;
                frq=find(arr,26);
                i++;
                diff=j-i+1-frq;
                
            }
            result = max(result,j-i+1);

        }
        return result;
    }
};