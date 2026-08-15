class Solution {
    void findthcombination(int idx,vector<int>&ds,int target,vector<int>&arr,vector<vector<int>>&ans){
        if(target==0){
            ans.push_back(ds);
            return;
        }
        for(int i=idx;i<arr.size();i++){
            if(i>idx&&arr[i]==arr[i-1]) continue;
            if(arr[i]>target) break;
            ds.push_back(arr[i]);
            findthcombination(i+1,ds,target-arr[i],arr,ans);
            ds.pop_back();
        }             
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>ds;
        sort(candidates.begin(),candidates.end());
        findthcombination(0,ds,target,candidates,ans);
        return ans;
    }
};