class Solution {
    int cntlessthangoal(int goal,vector<int>&nums){
    
    if(goal<0) return 0;

    int left=0;
    int sum=0;
    int cnt=0;
    int n=nums.size();
    for(int right=0;right<n;right++){
        sum+=nums[right];

        while(sum>goal){
            sum-=nums[left];
            left++;
        }
        cnt=cnt+(right-left+1);
    }
    return cnt;
    }

public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
      int n=nums.size();
      if(n<goal) return 0;

      return cntlessthangoal(goal,nums)-cntlessthangoal(goal-1,nums);
    }
};