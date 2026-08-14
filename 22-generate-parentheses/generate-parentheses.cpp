class Solution {
    void formparenthesis(vector<string>&ans,int idx,string s,int n,int cnt0,int cnt1){
        //vector<string>ans;
        if(idx==2*n) {
            ans.push_back(s);
            return ;
        }
        if(cnt0<n){
        formparenthesis(ans,idx+1,s+"(",n,cnt0+1,cnt1);
        }
        if(cnt1<cnt0){
            formparenthesis(ans,idx+1,s+")",n,cnt0,cnt1+1);           
        }
        //return ans;
    }
public:
    vector<string> generateParenthesis(int n) {
       vector<string>ans;
       formparenthesis(ans,0,"",n,0,0);
      return ans;

    }
};