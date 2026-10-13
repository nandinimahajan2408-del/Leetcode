class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        vector<int>nums2;
        for(int i=0;i<nums.size();i++){
            nums2.push_back(abs(nums[i]));
        }

        sort(nums2.begin(),nums2.end());
        int n=nums2.size();
        long long ans=0;

        int l=0,r=n-1;
        while(l<r){
            ans+=((nums2[r]*nums2[r])-(nums2[l]*nums2[l]));
            l++,r--;
        }
        if(l==r) ans+=(nums2[r]*nums2[r]);
        
        return ans;
    }
};