class Solution {
    void provinces(int i,vector<vector<int>>&isConnected,vector<int>&vis){
        vis[i]=1;
        for(int j=0;j<isConnected.size();j++){
            if(vis[j]==0&&isConnected[i][j]==1){
                provinces(j,isConnected,vis);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        int cnt=0;
        vector<int>vis(n+1,0);
        for(int i=0;i<n;i++){
           if(vis[i]==0){
            cnt++;
            provinces(i,isConnected,vis);
           }
        }
        return cnt;
    }
};