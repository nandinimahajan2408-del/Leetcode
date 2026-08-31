class Solution {
public:
    int countPrimes(int n) {
         if(n<=2) return 0;
       vector<bool>primeno(n,true);
      
       primeno[0]=primeno[1]=false; 
       for(int i=3;(long long)i*i<n;i+=2){
        if(primeno[i]){
            for(long long j=(long long)i*i ; j<n ; j+=2*i){
                primeno[j]=false;;
            }
        }
       }
int cnt=1;
       for(int i=3;i<n;i+=2){
        if(primeno[i]) {
            cnt++;
        }
       }
       return cnt;
    }
};