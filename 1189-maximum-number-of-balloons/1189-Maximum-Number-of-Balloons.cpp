class Solution {
public:
    int maxNumberOfBalloons(string text) {
      unordered_map <char,int> have;
      unordered_map <char,int> need;
      int result =INT_MAX;
      string s = "balloon"; 
      for(int i=0;i<text.size();i++){
        have[text[i]]++;
      }
      for(int i=0 ; i<s.size();i++){
        need[s[i]]++;
      }
      for(auto i : need){
        char key = i.first;
        result=min(result,have[key]/need[key]);
      }
      return result;

    }
};