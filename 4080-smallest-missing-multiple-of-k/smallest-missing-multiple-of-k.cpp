class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        map<int,int>mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        int j=1;
        while(true){
            if(mpp.find(k*j)==mpp.end()){
                return k*j;
            }
            j++;
        }
        //return -1;
    }
};