class Solution {
public:
    bool checkString(string s) {
      int n=s.size();
      int aidx=-1;
      int bidx=n;

      for(int i=0;i<n;i++){
        if(s[i]=='a') aidx=max(aidx,i);
        if(s[i]=='b'){
            bidx=min(bidx,i);
        }
      }
      return aidx<bidx;  
    }
};