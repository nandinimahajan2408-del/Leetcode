class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        vector<pair<int,int>>ones1;
        vector<pair<int,int>>ones2;
        int n=img1.size();
        int m=img1[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(img1[i][j]==1){
                    ones1.push_back({i,j});
                }
                if(img2[i][j]==1){
                    ones2.push_back({i,j});
                }
            }
        }
        int overlap=0;
        unordered_map<string,int>mpp;
        for(int i=0;i<ones1.size();i++){
            int r1=ones1[i].first;
            int c1=ones1[i].second;
            for(int j=0;j<ones2.size();j++){
                int r2=ones2[j].first;
                int c2=ones2[j].second;

                int dr=r2-r1;
                int dc=c2-c1;

                string key=to_string(dr)+","+to_string(dc);
                mpp[key]++;
                overlap=max(mpp[key],overlap);
            }
        }
        return overlap;
    }
};