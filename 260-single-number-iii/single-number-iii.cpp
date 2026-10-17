class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
      int n=nums.size();

      long long xorr=0;
      for(int i=0;i<n;i++){
        xorr=xorr^nums[i];
      }

      int mask=(xorr&(-xorr));

      int grp1=0;
      int grp2=0;
      for(int i=0;i<n;i++){
        if((mask&nums[i])!=0) grp1=grp1^nums[i];
        else grp2=grp2^nums[i];
      }

       return{grp1,grp2};  
    }
};