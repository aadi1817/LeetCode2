class Solution {
public:
    int helper(int i,int j,string s1,string s2,vector<vector<int>>& dp){
        if(i<0) return j+1;
        if(j<0) return i+1;
        if(s1[i]==s2[j]) return helper(i-1,j-1,s1,s2,dp);
        if(dp[i][j]!=-1) return dp[i][j];
        int ins=1+helper(i,j-1,s1,s2,dp);
        int del=1+helper(i-1,j,s1,s2,dp);
        int rep=1+helper(i-1,j-1,s1,s2,dp);
        return dp[i][j]=min(rep,min(ins,del));
    }
    int minDistance(string s1, string s2) {
        int n=s1.length();
        int m=s2.length();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return helper(n-1,m-1,s1,s2,dp);
    }
};