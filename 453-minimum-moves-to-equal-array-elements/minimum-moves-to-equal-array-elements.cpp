class Solution {
public:
    int minMoves(vector<int>& nums) {
        //just assume we have to declare to become min
        int mini=INT_MAX;
        int n=nums.size();
        for(int i=0;i<n;i++){
            mini=min(mini,nums[i]);
        }
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i]-mini;
        }
        return sum;
    }
};