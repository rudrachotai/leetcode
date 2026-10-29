class Solution {
public:
    long long m = 1e9+7;
    int binaryexp(long long a,long long b){
        if(b==0) return 1;
        long long half = binaryexp(a,b/2);
        long long res = (half*half)%m;
        if(b%2==1) res=(res*a)%m;
        return (res)%m;
    }
    int countGoodNumbers(long long n) {
     long long evenplaces = (n+1)/2;
     long long oddplaces  =  n/2;
     return ((long long)binaryexp(5,evenplaces) * binaryexp(4,oddplaces))%m;
    }
};