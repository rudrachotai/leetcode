class Solution {
public:
    bool isPalindrome(string s) {
        
        string s1;
        for(int i=0;i<s.size();i++){
          if((s[i]>=65 && s[i]<=90) || (s[i]>=97 && s[i]<=122) || (s[i]>='0' && s[i]<='9'))  s1.push_back((char)tolower(s[i]));

        }
        int i=0;
        int j=s1.size()-1;
        while(i<=j){
          if(s1[i]==s1[j]){
           i++;
          j--;
                          }
          else return false;
        }
        return true;
    }
};