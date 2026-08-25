class Solution {
public:
    void bfs(int i,int j,vector<vector<bool>>& visited,vector<vector<char>>& grid){
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;
        q.push({i,j});
        visited[i][j]=true;
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            if(row-1>=0 && grid[row-1][col]=='1' && !visited[row-1][col]){
                q.push({row-1,col});
                visited[row-1][col]=true;
            }
            if(row+1<n && grid[row+1][col]=='1' && !visited[row+1][col]){
                q.push({row+1,col});
                visited[row+1][col]=true;
            }
            if(col-1>=0 && grid[row][col-1]=='1' && !visited[row][col-1]){
                q.push({row,col-1});
                visited[row][col-1]=true;
            }
            if(col+1<m && grid[row][col+1]=='1' && !visited[row][col+1]){
                q.push({row,col+1});
                visited[row][col+1]=true;
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j]=='1'){
                    bfs(i,j,visited,grid);
                    ans++;
                }
            }
        }
        return ans;
    }
};