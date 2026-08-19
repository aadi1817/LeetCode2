class Solution {
public:
    void dfs(int node,vector<bool>& visited,vector<vector<int>> adj){
        visited[node]=true;
        for(auto x:adj[node]){
            if(!visited[x]){
                dfs(x,visited,adj);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1 && i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int ans=0;
        vector<bool> visited(n,false);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i,visited,adj);
                ans++;
            }
        }
        return ans;
    }
};