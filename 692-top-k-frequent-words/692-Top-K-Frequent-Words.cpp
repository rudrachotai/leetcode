class Solution {
public:
    struct cmp{
         bool operator()(pair<int,string> &a,pair<int,string> &b){
        if(a.first!=b.first){
            return a.first>b.first;
        }    
            return a.second<b.second;
         }
     };
    vector<string> topKFrequent(vector<string>& words, int k) {
      priority_queue<pair<int,string>,vector<pair<int,string>>,cmp> mmheap;
      unordered_map <string,int> map;
      for(int i=0;i<words.size();i++){
          map[words[i]]++;
      }  
      int j=0;
      for(auto ele: map){
          pair <int,string> p = {ele.second,ele.first};
          if(j<k){
              mmheap.push(p);
              j++;
              continue;
          }
          if(mmheap.top().first>ele.second) continue;
          if(mmheap.top().second<=ele.first && mmheap.top().first==ele.second ) continue;
          mmheap.pop();
          mmheap.push(p);
      }
      vector<string> res;
      while(mmheap.size()!=0){
          res.insert(res.begin(),(mmheap.top().second));
          mmheap.pop();
      }
      
      return res;
    }
};