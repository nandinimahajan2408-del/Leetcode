class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n=s.size();
        int m=s.size();
        if(n!=m) return false;
       
       //check whether last seen idx is same or not 
       vector<int>idxs(256,0);
       vector<int>idxt(256,0);

       for(int i=0;i<n;i++){
        if(idxs[s[i]]!=idxt[t[i]]) return false;
        idxs[s[i]]=i+1;
        idxt[t[i]]=i+1;
       }
       return true;
    }
};