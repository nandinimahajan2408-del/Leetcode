class Solution {
public:
    int reverseDegree(string s) {
      int n=s.size();
      int ans=0;
      for(int i=0;i<n;i++){
        int alpha=26-(s[i]-'a');
        ans=ans+((i+1)*alpha);
      }
      return ans;  
    }
};