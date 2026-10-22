class Solution {
public:
    void comb(string digits,unordered_map <char,string> m,int idx,string temp,vector<string> &ans){
     if(idx == digits.size()){
        ans.push_back(temp);
        return;
     }
      string choice = m[digits[idx]];
      for(int i=0;i<choice.size();i++){
        temp.push_back(choice[i]);
        comb(digits,m,idx+1,temp,ans);
        temp.pop_back();
      }
      return;
    }
    vector<string> letterCombinations(string digits) {
        unordered_map <char,string> m;
        string temp;
        vector<string> ans;
        m['2'] = "abc";
        m['3'] = "def";
        m['4'] = "ghi";
        m['5'] = "jkl";
        m['6'] = "mno";
        m['7'] = "pqrs";
        m['8'] = "tuv";
        m['9'] = "wxyz";
        comb(digits,m,0,temp,ans);
        return ans;
    }
};