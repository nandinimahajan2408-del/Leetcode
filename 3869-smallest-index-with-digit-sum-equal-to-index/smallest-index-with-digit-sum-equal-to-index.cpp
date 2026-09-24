class Solution {
public:
    int smallestIndex(vector<int>& nums) {
       int n=nums.size();
       for(int i=0;i<n;i++){
        int sum=0;
        int nn=nums[i];
        while(nn>0){
            sum+=nn%10;
            nn=nn/10;
        }
        if(sum==i)return i;
       }
       return -1; 
    }
};