class Solution {
    void dfs(vector<vector<int>>&grid,vector<vector<int>>&vis,int row,int col){
         vis[row][col]=1;
         vector<int>delrow={-1,0,1,0};
       vector<int>delcol={0,1,0,-1};

       int n=grid.size();
       int m=grid[0].size();
        for(int i=0;i<4;i++){
            int r=row+delrow[i];
            int c=col+delcol[i];

            if(r>=0&&r<n&&c>=0&&c<m&&grid[r][c]==0&&vis[r][c]==0){
               dfs(grid,vis,r,c);
            }
        }
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
       vector<vector<int>>vis(n,vector<int>(m,0));

       //queue<pair<int,int>>q;

       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0||j==0||i==n-1||j==m-1){
                if(grid[i][j]==0){
                    dfs(grid,vis,i,j);
                }
            }
        }
       }

       int cnt=0;
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==0&&vis[i][j]==0){
                cnt++;
                dfs(grid,vis,i,j);
            }
        }
       }
       return cnt;
    }
};