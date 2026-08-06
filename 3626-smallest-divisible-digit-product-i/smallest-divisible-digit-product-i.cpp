class Solution {
public:
    int smallestNumber(int n, int t) {
        for(int i=n;i<=n+10;i++){
            int ans=1;
            int nn=i;
            while(nn>0){
                int rem=nn%10;
                ans=ans*rem;
                nn=nn/10;
            }
            if(ans%t==0) return i;
        }
        return -1;
    }
};