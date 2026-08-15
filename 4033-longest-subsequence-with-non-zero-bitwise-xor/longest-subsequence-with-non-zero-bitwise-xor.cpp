class Solution {
public:
    int longestSubsequence(vector<int>&nums) {
       int xorr=0;
       int n=nums.size();

       bool allzero=true;

       for(int i=0;i<n;i++){
        if(nums[i]!=0){
            allzero=false;
        }
        xorr=xorr^nums[i];
       } 
       if(allzero==true) return 0;
       if(xorr!=0) return n;
       return n-1;
    }
};