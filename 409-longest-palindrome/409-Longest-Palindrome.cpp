class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map <char,int> map;
        int result=0;
        bool isodd = false;
        for(int i=0;i<s.size();i++){
            map[s[i]]++;
        }
        for(auto i:map){
            int n = i.second;
            if(n%2==0){
            result+=n;
            }
            else{
            result+=n-1;
            isodd = true;
            }
           
        }
        if(isodd==true) result+=1;
        return result;
    }
};