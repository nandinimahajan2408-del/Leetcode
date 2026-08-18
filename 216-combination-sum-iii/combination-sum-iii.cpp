class Solution {
    void findlist(int k,int sum,int no,vector<vector<int>>&ans,vector<int>ds){
       if(k==0){
        if(sum==0) ans.push_back(ds);
        return;
       }

       for(int i=no;i<=9;i++){
        if(i>sum) break;

        ds.push_back(i);
        findlist(k-1,sum-i,i+1,ans,ds);
        ds.pop_back();
       }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>ds;
      findlist(k,n,1,ans,ds); 
      return ans; 
    }
};