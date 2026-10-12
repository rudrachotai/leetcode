class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int i=0;i<stones.size();i++){
           pq.push(stones[i]);
        }
        while(pq.size()!=0){
            if(pq.size()==1) return pq.top();
            int y = pq.top();
            pq.pop();
            int x = pq.top();
            pq.pop();
            if(y-x>0) pq.push(y-x);
        }
        return 0;
    }
};