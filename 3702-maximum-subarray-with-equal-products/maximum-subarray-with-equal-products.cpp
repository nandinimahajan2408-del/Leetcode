class Solution {
public:
    int maxLength(vector<int>& nums) {
      int maxilen=2;
        //possible when two no cant share any factor
        int pro=1;
        int l=0;
        int r=0;
        int n=nums.size();
        while(r<n){
            while(gcd(pro,nums[r])>1){
                pro=pro/nums[l];
                l++;
            }
            pro=pro*nums[r];
            maxilen=max(maxilen,r-l+1);
            r++;
        }
        return maxilen;
    }
    };
 