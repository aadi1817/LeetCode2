class Solution {
public:
    bool isMatch(string s, string p) {
        int m=s.length();
        int n=p.length();
        vector<bool> dp(m+1,false),curr(m+1,false);
        dp[0]=true;
        for(int j=1;j<m+1;j++) dp[j]=false;
        for(int i=1;i<n+1;i++){
            bool flag=true;
            for(int k=1;k<i+1;k++){
                if(p[k-1]!='*') flag=false;
            }
            curr[0]=flag;
            for(int j=1;j<m+1;j++){
                if(p[i-1]==s[j-1] || p[i-1]=='?') curr[j]=dp[j-1];
                else if(p[i-1]=='*') curr[j]=dp[j] || curr[j-1];
                else curr[j]=false;
            }
            dp=curr;
        }
        return dp[m];
    }
};