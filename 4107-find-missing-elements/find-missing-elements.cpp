class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
      int n=nums.size();
      unordered_set<int>presentele;
      int mini=INT_MAX;
      int maxi=INT_MIN;
      for(int i=0;i<n;i++){
        mini=min(mini,nums[i]);
        maxi=max(maxi,nums[i]);
       presentele.insert(nums[i]);
      }  
      vector<int>ans;
      for(int i=mini+1;i<maxi;i++){
        if(presentele.find(i)==presentele.end()){
            ans.push_back(i);
        }
      }
      return ans;
    }
};