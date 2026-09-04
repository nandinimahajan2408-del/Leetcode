class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
       vector<int>ans;
       int maxi=INT_MIN;
       for(int i=0;i<nums.size();i++){
        maxi=max(maxi,nums[i]);
        int mini=INT_MAX;
        for(int j=i;j<nums.size();j++){
            mini=min(mini,nums[j]);
        }
        ans.push_back(maxi-mini);
       } 
       int fans=-1;
       for(int i=0;i<ans.size();i++){
        if(ans[i]<=k){
        return i;
        }
       }
       return fans;
    }
};