class Solution {
    int cntlessthano(vector<int>&nums,int lim){
        map<int,int>mpp;
        if(lim<=0){
            return 0;
        } 
       int left=0;
       int cnt=0;
       int n=nums.size();
          for(int right=0;right<n;right++){
        mpp[nums[right]]++;

        while(mpp.size()>lim){
            int val=nums[left];
            mpp[nums[left]]--;
            
            if(mpp[val]==0) {
                mpp.erase(val);
            }
            left++;
            
        }
        cnt+=right-left+1;
       }
       return cnt; 
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
      return cntlessthano(nums,k)-cntlessthano(nums,k-1);
      
    }
};