class Solution {
    bool ispalindrome(int i,int j,string s,int n){
        while(i<j){
            if(s[i]!=s[j]) return false;
             i++,j--;
        }
            return true;
    }
    void f(int i,vector<vector<string>>&ans,vector<string>&ds,int n,string s){
        if(i==n){
            ans.push_back(ds);
            return;
        }
        for(int j=i;j<n;j++){
            if(ispalindrome(i,j,s,n)){
                ds.push_back(s.substr(i,j-i+1));
                f(j+1,ans,ds,n,s);
                ds.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        int n=s.size();
        vector<vector<string>>ans;
        vector<string>ds;
        f(0,ans,ds,n,s);
        return ans;
    }
};