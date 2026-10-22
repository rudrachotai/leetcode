class Solution {
public: 
     void rparenthesis(string &temp,vector<string> &vec,int open,int close,int n){
         if(open==n && close==n){
            vec.push_back(temp);
            return;
         }

         if(open<n){
            temp.push_back('(');
            rparenthesis(temp,vec,open+1,close,n);
            temp.pop_back();
         }
         if(close<open){
             temp.push_back(')');
             rparenthesis(temp,vec,open,close+1,n);
             temp.pop_back();
         }
     } 
    vector<string> generateParenthesis(int n) {
        string temp = "";
        vector<string> ans;
        rparenthesis(temp,ans,0,0,n);
        return ans;
    }
};