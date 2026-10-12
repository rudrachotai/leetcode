class Solution {
public:
    struct cmp{
     bool operator()(const pair <int,char> &a,const pair <int,char> &b){
         if(a.first!=b.first){
             return a.first<b.first;
         }
         return a.second<b.second;
     }  
    };
    string reorganizeString(string s) {
      unordered_map <char,int> map;
      priority_queue<pair<int,char>,vector<pair<int,char>>,cmp> pq;
      for(int i=0;i<s.size();i++){
          map[s[i]]++;
      }
      for(auto ele:map){
          pair <int,char> p = {ele.second,ele.first};
          pq.push(p);
      }
     string result = "";
     int seat = 0;
      while(seat<s.size() && pq.size()!=0){
          pair <int,char> p = pq.top();
          pq.pop();
          if(seat==0) {
              result.push_back(p.second);
              p.first--;
              seat++;
              if(p.first>0)  pq.push(p);
              }
              
          else{
              if(result[seat-1]!=p.second) {
                  result.push_back(p.second);
                  p.first--;
                  seat++;
                  if(p.first>0)  pq.push(p);
                  }
              else {
                 if(pq.size()==0) return "";
                 pair <int,char> p2 = pq.top(); 
                 pq.pop();
                 result.push_back(p2.second);
                  p2.first--;
                  seat++;
                 
                 if(p2.first>0) pq.push(p2);
                 if(p.first>0)  pq.push(p);
              }
          }
        
      }
        return result;
    }
};