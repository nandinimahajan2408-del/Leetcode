class Solution {
public:
    int maximumLengthSubstring(string s) {
       int n=s.size();
   // vector<int>hashmapp(256)={0};
    map<char,int>mpp;
       int maxlen=0;
       int l=0,r=0;
       while(r<n){
      //hashmapp[s[r]]++;
      mpp[s[r]]++;
      while(mpp[s[r]]>2){
        mpp[s[l]]--;
        l=l+1;
      }
      maxlen=max(maxlen,r-l+1);
      r++;
       }
       return maxlen; 
    }
};