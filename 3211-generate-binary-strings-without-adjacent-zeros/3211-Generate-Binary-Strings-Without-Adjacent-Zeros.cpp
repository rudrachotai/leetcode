class Solution {
public:
   void helper(string &temp,vector<string> &res,int n){
     if(temp.size()==n) {
    res.push_back(temp);
     return;
     }
    temp.push_back('1');
    helper(temp,res,n);
    temp.pop_back();
    if(temp.size()==0 || temp[temp.size()-1]=='1') 
    {   temp.push_back('0');
        helper(temp,res,n);
        temp.pop_back();
    
    }
      
        
      
     
   }
    vector<string> validStrings(int n) {
        vector<string> res;
        string temp = "";
        helper(temp,res,n);
        return res;
    }
};