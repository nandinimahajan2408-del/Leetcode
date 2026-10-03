class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      vector<int>hashmapp(256,-1);
     int l=0,r=0;
      int n=s.size();
      int maxi=0;
      int len;
     
     while(r<n){
        if(hashmapp[s[r]]!=-1){
            //that means it already exit
            if(l<=hashmapp[s[r]]){
                l=hashmapp[s[r]]+1;
            }
        }
        hashmapp[s[r]]=r;
        len=r-l+1;
        maxi=max(maxi,len);
        r++;
     }
      return maxi;  
    }
};