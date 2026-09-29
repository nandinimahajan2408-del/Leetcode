class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
      vector<int>startt;
      vector<int>ends;
      int n=intervals.size();

      for(int i=0;i<n;i++){
        startt.push_back(intervals[i][0]);
        ends.push_back(intervals[i][1]);
      }
      sort(startt.begin(),startt.end());
      sort(ends.begin(),ends.end());

      int cnt=0;
      int maxi=0;
      int i=0,j=0;
      while(i<n){
        if(startt[i]<=ends[j]){
            cnt++;
            i=i+1;
        }else{
            cnt--;
            j=j+1;
        }
        maxi=max(maxi,cnt);
      }
      return maxi;
    }
};