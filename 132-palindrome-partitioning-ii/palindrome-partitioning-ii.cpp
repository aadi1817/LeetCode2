class Solution {
public:
    int minCut(string s) {
        int n=s.length();
        vector<vector<bool>> palin(n,vector<bool>(n,false));
        for(int i=0;i<n;i++){
            palin[i][i]=true;
        }
        for(int len=2;len<=n;len++){
            for(int i=0;i+len-1<n;i++){
                int j=i+len-1;
                if(s[i]==s[j]){
                    if(len==2){
                        palin[i][j]=true;
                    }else{
                        palin[i][j]=palin[i+1][j-1];
                    }
                }
            }
        }
        vector<int> dp(n+1,0);
        for(int i=n-1;i>=0;i--){
            int mini=INT_MAX;
            for(int j=i;j<s.length();j++){
                if(palin[i][j]){
                    int cost=1+dp[j+1];
                    mini=min(mini,cost);
                }
            }
            dp[i]=mini;
        }
        return dp[0]-1;
    }
};