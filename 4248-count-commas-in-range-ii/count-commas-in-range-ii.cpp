class Solution {
public:
    long long countCommas(long long n) {
      long long total=0;
      long long start=1000;

      while(start<=n){
        total+=(n-start+1);
        start=start*1000;
      }
      return total;
    }
};