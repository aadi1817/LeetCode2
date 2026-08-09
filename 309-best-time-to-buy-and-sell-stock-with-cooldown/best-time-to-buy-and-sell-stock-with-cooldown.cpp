class Solution {
public:
    int helper(int i,int b,vector<int>& prices,vector<vector<int>>& dp){
        if(i>=prices.size()) return 0;
        if(dp[i][b]!=-1) return dp[i][b];
        if(b==1){
            return dp[i][b]=max(-prices[i]+helper(i+1,0,prices,dp),helper(i+1,1,prices,dp));
        }
        return dp[i][b]=max(prices[i]+helper(i+2,1,prices,dp),helper(i+1,0,prices,dp));
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return helper(0,1,prices,dp);
    }
};