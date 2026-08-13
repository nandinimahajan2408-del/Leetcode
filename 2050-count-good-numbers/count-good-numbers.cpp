class Solution {
    const int MOD=1e9+7;

    long long power(long long base,long long nn){
        
        long long res=1;
        base=base%MOD;
        while(nn){
            if(nn%2==1) res=(res*base)%MOD;
            base=(base*base)%MOD;
            nn=nn/2;
        }
        return res;
    }
public:
    int countGoodNumbers(long long n) {
      
     long long even=(n+1)/2;
     long long odd=(n/2);

      long long first=power(5,even);
      long long second=power(4,odd);

      return (first*second)%MOD;

    }
};