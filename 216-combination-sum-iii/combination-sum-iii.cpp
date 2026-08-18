class Solution {
    void findlist(int k,int sum,int no,vector<vector<int>>&ans,vector<int>ds){
        if(sum==0&&k==0) {
            ans.push_back(ds);
            return;
        }
        if(no>9||sum<0||k<0) return;
        ds.push_back(no);
        sum=sum-no;
        findlist(k-1,sum,no+1,ans,ds);
        ds.pop_back();
        sum=sum+no;
        findlist(k,sum,no+1,ans,ds);
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>ds;
      findlist(k,n,1,ans,ds); 
      return ans; 
    }
};