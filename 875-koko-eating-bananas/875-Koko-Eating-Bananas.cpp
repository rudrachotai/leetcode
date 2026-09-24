class Solution {
public:
    int findmax(vector<int> &piles){
        int rmax = piles[0];
        for(int i=1; i<piles.size();i++){
            rmax = max(rmax,piles[i]);
        }
        return rmax;
        
    }
    long long noofhours(int speed,vector<int>& piles){
        long long hours = 0;
        for(int i=0;i<piles.size();i++){
            hours+=(piles[i]/speed);
            if(piles[i]%speed!=0) hours++;
        }
        return hours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int st = 1;
        int end = findmax(piles);
        int k = 0;
        int guess = st + (end-st)/2;
        while(st<=end){
              guess = st + (end-st)/2;
          long long hours = noofhours(guess,piles);
          if(hours>h){
             st = guess+1;
          } 
          else{
            k = guess;
            end = guess-1;
          } 
        }
        return k;
    }
};