class Solution {
    void dfs(vector<vector<int>>& grid,vector<vector<int>>&vis,int row,int col,long long &sum){
        vis[row][col]=1;
        int n=grid.size();
        int m=grid[0].size();
        vector<int>delrow={-1,0,1,0};
        vector<int>delcol={0,1,0,-1};
        for(int i=0;i<4;i++){
            int r=row+delrow[i];
            int c=col+delcol[i];
            if(r>=0&&r<n&&c>=0&&c<m&&vis[r][c]==0&&grid[r][c]!=0){
                sum+=grid[r][c];
                dfs(grid,vis,r,c,sum);
            }
        }
    }
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();

      vector<vector<int>>vis(n,vector<int>(m,0));
      int cnt=0;
      for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]!=0&&vis[i][j]==0){
                long long sum=grid[i][j];
                dfs(grid,vis,i,j,sum);
                if(sum%k==0)cnt++;
            }
        }
      }
      return cnt;  
    }
};