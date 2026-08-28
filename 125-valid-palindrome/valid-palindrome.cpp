class Solution {
public:
    bool isPalindrome(string s) {
      string ans="";
      for(int i=0;i<s.size();i++){
        if(s[i]<=90&&s[i]>=65) ans.push_back(s[i]+32);
        if(s[i]<=122&&s[i]>=97) ans.push_back(s[i]);
        if(s[i]<='9'&&s[i]>='0') ans.push_back(s[i]);
      }
       int n=ans.size();
      int r=n-1;
      int l=0;
      while(l<r){
        if(ans[l]!=ans[r]) return false;
        r--;
        l++;
      }
      return true;  
    }
};