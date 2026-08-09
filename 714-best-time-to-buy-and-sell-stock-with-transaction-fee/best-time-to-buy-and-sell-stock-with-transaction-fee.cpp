class Solution {
public:
    int maxProfit(vector<int>& prices,int fee) {
        int n=prices.size();
        vector<int> dp(2,0),curr(2,0);
        for(int i=n-1;i>=0;i--){
            curr[1]=max(-prices[i]-fee+dp[0],dp[1]);
            curr[0]=max(prices[i]+dp[1],dp[0]);
            dp=curr;
        }
        return dp[1];
    }
};