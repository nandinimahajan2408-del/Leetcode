class Solution {
public:
    bool isPalindrome(int x) {
      if(x<0) return false;
      int xx=x;
      long long ans=0;
      while(xx>0){
        int rem=xx%10;
        ans=ans*10+rem;
        xx=xx/10;
      }  
    
    if(x!=ans) return false;
    return true;
    }
};