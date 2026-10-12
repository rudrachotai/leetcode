class Solution {
public:
 struct cmp{
     bool operator()(const pair <int,int> &a,const pair <int,int> &b){
         if(a.first!=b.first){
             return a.first<b.first;
         }
         return a.second>b.second;
     }  
    };
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue <pair<int,int>,vector<pair<int,int>>,cmp> pq;
        vector <pair<int,int>> vec;
        for(int i=0;i<profits.size();i++){
            vec.push_back({capital[i],profits[i]});
        } 
        sort(vec.begin(),vec.end());
        int i=0;
        int j=0;
        while(i<k){
            
               while(j<vec.size() && w>=vec[j].first){
                pq.push({vec[j].second,vec[j].first});
                j++;
               }
               if(pq.size()==0) break;
                w+=pq.top().first;
                pq.pop();
            
            i++;
        }
        
          return w;
    }
};