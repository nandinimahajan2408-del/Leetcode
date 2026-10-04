class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
       int n=nums.size();
       int l=0;
      int maxi=0;
      int zerocnt=0;

      for(int r=0;r<n;r++){
        if(nums[r]==0){
            zerocnt++;
        }
        while(zerocnt>k){
            if(nums[l]==0) zerocnt--;
            l++;
        }
        int len=r-l+1;
        maxi=max(maxi,len);
      }
      return maxi;
    }
};