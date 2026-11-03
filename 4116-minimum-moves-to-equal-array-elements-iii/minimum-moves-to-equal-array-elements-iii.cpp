class Solution {
public:
    int minMoves(vector<int>& nums) {
       int maxi=INT_MIN;

       for(int i=0;i<nums.size();i++){
        maxi=max(maxi,nums[i]);
       } 
       int cnt=0;
       for(int i=0;i<nums.size();i++){
        if(nums[i]<maxi){
            cnt+=maxi-nums[i];
        }
       }
       return cnt;
    }
};