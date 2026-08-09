class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(2,vector<int>(k+1,0)),curr(2,vector<int>(k+1,0));
        for(int i=n-1;i>=0;i--){
            for(int b=0;b<=1;b++){
                for(int c=1;c<=k;c++){
                    if(b==1) curr[b][c]=max(-prices[i]+dp[0][c],dp[1][c]);
                    else curr[b][c]=max(prices[i]+dp[1][c-1],dp[0][c]);
                }
            }
            dp=curr;
        }
        return dp[1][k];
    }
};