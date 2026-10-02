class Solution {
    void formparenthesis(int n,int idx,string s,int cnt0,int cnt1,vector<string>&ans){
        if(2*n==idx){
            ans.push_back(s);
            return ;
        }
        if(cnt0<n){
            formparenthesis(n,idx+1,s+'(',cnt0+1,cnt1,ans);
        }
        if(cnt1<cnt0){
            formparenthesis(n,idx+1,s+')',cnt0,cnt1+1,ans);
        }
        return ;
    }
   
public:
    vector<string> generateParenthesis(int n) {
      vector<string>ans;
      formparenthesis(n,0,"",0,0,ans);
      return ans;
    }
};