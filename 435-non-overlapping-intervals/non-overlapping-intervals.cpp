class Solution {
    static bool comp(vector<int>val1,vector<int>val2){
        return val1[1]<val2[1];
    }
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
      sort(intervals.begin(),intervals.end(),comp);
      int cnt=1;
      int endtime=intervals[0][1];
      for(int i=1;i<intervals.size();i++){
        if(intervals[i][0]>=endtime){
            cnt++;
            endtime=intervals[i][1];
        }
      }
      return intervals.size()-cnt;  
    }
};