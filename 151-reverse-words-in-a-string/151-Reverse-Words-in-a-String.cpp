class Solution {
public:
    string reverseWords(string s) {
      string result = "";
      int n = s.size();
      reverse(s.begin(),s.end());
      int i = 0;
      int l = 0;
      int r = 0;
      while(i<n){
        while(i<n && s[i]!=' '){
            s[r] = s[i];
            r++;
            i++;
        }
         if(l<r){s[r] = ' ';
         reverse(s.begin()+l,s.begin()+r);
         r++;
         l = r;}
         i++;
      }

       if(r>=1) return s.substr(0, r-1);
       return s;
    }
};