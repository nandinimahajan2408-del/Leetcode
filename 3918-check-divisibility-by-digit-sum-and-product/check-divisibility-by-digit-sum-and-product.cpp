class Solution {
public:
    bool checkDivisibility(int n) {
      long long pro=1;
      long long sum=0;
      int nn=n;
     while(nn>0) {
        pro=pro*(nn%10);
        sum=sum+(nn%10);
        nn=nn/10;
     }
     if (n%(sum+pro)!=0) return false;
     return true;
    }
};