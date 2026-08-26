class Solution {
public:
    void dfs(int sr, int sc,vector<vector<int>>& ans,vector<vector<int>>& image,int ini,int color){
        if(sr<0 || sc<0 || sr>=image.size() || sc>=image[0].size() || ans[sr][sc]!=ini) return;
        ans[sr][sc]=color;
        dfs(sr-1,sc,ans,image,ini,color);
        dfs(sr,sc-1,ans,image,ini,color);
        dfs(sr+1,sc,ans,image,ini,color);
        dfs(sr,sc+1,ans,image,ini,color);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int ini=image[sr][sc];
        int n=image.size();
        int m=image[0].size();
        vector<vector<int>> ans=image;
        if(ini==color) return image;
        dfs(sr,sc,ans,image,ini,color);
        return ans;
    }
};