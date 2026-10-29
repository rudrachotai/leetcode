class Solution {
public:
   double solve(double x,long n){
    if(n==0) return 1;
    if(n%2==0) return solve(x*x,n/2);
    else return x*solve(x*x,(n-1)/2);
   }
    double myPow(double x, int n){
    long long N = n;
    if(n<0) {
       return 1.0 / solve(x, -N);
    }
    else return solve (x,n);
    }

    
};