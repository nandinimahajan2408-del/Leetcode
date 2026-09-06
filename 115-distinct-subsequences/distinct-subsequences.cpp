class Solution {
    int backtrack(int i,int j,string &s,string &t,vector<vector<int>>&dp){
        if(j==t.size()){
            return 1;
        }
        if(i==s.size()){
            return 0;
        }

        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==t[j]){
          dp[i][j]=(1LL*backtrack(i+1,j+1,s,t,dp)+backtrack(i+1,j,s,t,dp));
        }else{
           dp[i][j]= backtrack(i+1,j,s,t,dp);
        }
        return dp[i][j];
    }
public:
    int numDistinct(string s, string t) {
        vector<vector<int>>dp(s.size(),vector<int>(t.size(),-1));
       return backtrack(0,0,s,t,dp);
    }
};