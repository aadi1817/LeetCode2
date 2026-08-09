class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int> dp(2,0),curr(2,0),curr2(2,0);
        for(int i=n-1;i>=0;i--){
            for(int b=0;b<=1;b++){
                if(b==1) curr[b]=max(-prices[i]+dp[0],dp[1]);
                else curr[b]=max(prices[i]+curr2[1],dp[0]);
            }
            curr2=dp;
            dp=curr;
        }
        return dp[1];
    }
};