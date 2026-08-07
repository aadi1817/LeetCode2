class Solution {
public:
    int minDistance(string s1, string s2) {
        int n=s1.length();
        int m=s2.length();
        vector<int> dp(m+1,0),curr(m+1,0);
        for(int j=0;j<m+1;j++){
            dp[j]=j;
        }
        for(int i=1;i<n+1;i++){
            curr[0]=i;
            for(int j=1;j<m+1;j++){
                if(s1[i-1]==s2[j-1]) curr[j]=dp[j-1];
                else{
                    int ins=1+curr[j-1];
                    int del=1+dp[j];
                    int rep=1+dp[j-1];
                    curr[j]=min(rep,min(ins,del));
                }
            }
            dp=curr;
        }
        return dp[m];
    }
};