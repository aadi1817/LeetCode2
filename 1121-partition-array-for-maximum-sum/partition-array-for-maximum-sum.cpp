class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> dp(n+1,0);
        for(int i=n-1;i>=0;i--){
            int ans=INT_MIN;
            int maxi=INT_MIN;
            for(int j=i;j<arr.size() && j<i+k;j++){
                maxi=max(maxi,arr[j]);
                int cost=((j-i+1)*maxi)+dp[j+1];
                ans=max(ans,cost);
            }
            dp[i]=ans;
        }
        return dp[0];
    }
};