class Solution {

    int cntlessthank(vector<int>&arr,int k){
        if(k<0)return 0;

        int left=0;
        int sum=0;
        int cnt=0;

        for(int right=0;right<arr.size();right++){
            sum+=arr[right];

            while(sum>k){
                sum-=arr[left];
                left++;
            }

            cnt+=right-left+1;
        }
        return cnt;
    }
    
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
      int n=nums.size();

      vector<int>arr;
      for(int i=0;i<n;i++){
        if(nums[i]%2==0)arr.push_back(0);
        else arr.push_back(1);
      }

      return cntlessthank(arr,k)-cntlessthank(arr,k-1);  
    }
};