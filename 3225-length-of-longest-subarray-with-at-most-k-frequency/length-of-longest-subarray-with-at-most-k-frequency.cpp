class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
       int l=0,r=0;
       int len=0;
       int n=nums.size();
       unordered_map<int,int>mpp;
       while(l<=r&&r<n){
        mpp[nums[r]]++;
        while(mpp[nums[r]]>k){
            mpp[nums[l]]--;
            l=l+1;
        }
        len=max(len,r-l+1);
        r++;
       }
       return len;
    }
};