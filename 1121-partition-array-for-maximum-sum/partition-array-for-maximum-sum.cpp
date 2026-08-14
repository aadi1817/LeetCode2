class Solution {
public:
    int helper(int i,int k,vector<int>& arr,vector<int>& dp){
        if(i==arr.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        int ans=INT_MIN;
        int maxi=INT_MIN;
        for(int j=i;j<arr.size() && j<i+k;j++){
            maxi=max(maxi,arr[j]);
            int cost=((j-i+1)*maxi)+helper(j+1,k,arr,dp);
            ans=max(ans,cost);
        }
        return dp[i]=ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> dp(n,-1);
        return helper(0,k,arr,dp);
    }
};