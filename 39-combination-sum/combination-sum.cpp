class Solution {
    void findthcombination(int idx,vector<int>&ds,int target,vector<vector<int>>&ans,vector<int>&arr){
        if(target==0){
            ans.push_back(ds);
            return;
        }

        if(idx==arr.size()){
            return;
        }
        if(arr[idx]<=target){
            ds.push_back(arr[idx]);
            findthcombination(idx,ds,target-arr[idx],ans,arr);
            ds.pop_back();
        }
        findthcombination(idx+1,ds,target,ans,arr);
        
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
       vector<vector<int>>ans;
       vector<int>ds;
       findthcombination(0,ds,target,ans,candidates);
       return ans; 
    }
};