class Solution {
public:
    int maxDepth(string s) {
       int left=0;
       int right=0;
       int maxi=INT_MIN;
       int n=s.size();
       for(int i=0;i<n;i++){
        if(s[i]=='(') left++;
        if(s[i]==')') right++;
         if(maxi<(left-right)){
                maxi=left-right;
            }
       }
       return maxi; 
    }
};