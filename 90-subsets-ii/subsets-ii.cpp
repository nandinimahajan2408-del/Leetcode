class Solution {
    void  findsubset(int idx,vector<int>&ds,vector<vector<int>>&ans,int n,vector<int>&nums){
        ans.push_back(ds);
        for(int i=idx;i<n;i++){
            if(i>idx&&nums[i]==nums[i-1]) continue;
            ds.push_back(nums[i]);
            findsubset(i+1,ds,ans,n,nums);
            ds.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
       int n=nums.size();
       vector<vector<int>>ans;
       vector<int>ds;
       sort(nums.begin(),nums.end());
       findsubset(0,ds,ans,n,nums); 
       return ans;
    }
};