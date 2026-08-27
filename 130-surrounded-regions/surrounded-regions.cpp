class Solution {
public:
    void dfs(int row,int col,vector<vector<char>>& grid,vector<vector<int>>& visited){
        visited[row][col]=1;
        vector<int> drow={-1,0,1,0};
        vector<int> dcol={0,1,0,-1};
        for(int i=0;i<4;i++){
            int nrow=row+drow[i];
            int ncol=col+dcol[i];
            if(nrow>=0 && ncol>=0 && nrow<grid.size() && ncol<grid[0].size() && grid[nrow][ncol]=='O' && visited[nrow][ncol]==0){
                dfs(nrow,ncol,grid,visited);
            }
        }
    }
    void solve(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            if(grid[i][0]=='O' && visited[i][0]==0) dfs(i,0,grid,visited);
            if(grid[i][m-1]=='O' && visited[i][m-1]==0) dfs(i,m-1,grid,visited);
        }
        for(int j=0;j<m;j++){
            if(grid[0][j]=='O' && visited[0][j]==0) dfs(0,j,grid,visited);
            if(grid[n-1][j]=='O' && visited[n-1][j]==0) dfs(n-1,j,grid,visited);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='O' && visited[i][j]==0) grid[i][j]='X';
            }
        }
    }
};