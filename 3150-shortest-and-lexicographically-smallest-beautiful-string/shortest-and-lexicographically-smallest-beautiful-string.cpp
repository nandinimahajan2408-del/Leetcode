class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n=s.size();
        int l=0;
        int flen=INT_MAX;
        string ans="";
        int total=0;
        for(int r=0;r<n;r++){
            if(s[r]=='1') total++;
            while(total==k){
                 string curr=s.substr(l,r-l+1);
                if(r-l+1<flen){
                    flen=r-l+1;
                    ans=curr;
                }else if(r-l+1==flen){
                    if(curr<ans) ans=curr;
                }
               
        
                if(s[l]=='1') total--;
                l++;
            }
           
        }
        return ans;
    }
};