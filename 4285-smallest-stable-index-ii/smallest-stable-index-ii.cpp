class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
       vector<int>prefmax(nums.size());
       vector<int>suffmin(nums.size());
       int n=nums.size();
       int maxi=INT_MIN;
       int mini=INT_MAX;
       for(int i=0;i<nums.size();i++){
        maxi=max(maxi,nums[i]);
        prefmax[i]=maxi;
        mini=min(mini,nums[n-i-1]);
        suffmin[n-i-1]=mini;
       }

       for(int i=0;i<nums.size();i++){
        if(prefmax[i]-suffmin[i]<=k) return i;
       }
       return -1; 
    }
};