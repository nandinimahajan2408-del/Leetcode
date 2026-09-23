class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int maxlen=-1;
        int totalsum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            totalsum+=nums[i];
        }
        int target=totalsum-x;
        if(target<0)return -1;
        if(target==totalsum) return n;

        int left=0;
        int currsum=0;
        for(int right=0;right<n;right++){
            currsum+=nums[right];
            while(currsum>target&&left<=right){
                currsum-=nums[left];
                left++;
            }
            if(target==currsum){
                maxlen=max(maxlen,right-left+1);
            }
        }
        if(maxlen==-1) return -1;
        return n-maxlen;;
    }
};