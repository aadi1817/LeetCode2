class Solution {
public:
    bool compare(string a,string b){
        if(a.length()!=b.length()+1) return false;
        bool poss=true;
        int i=0;
        int j=0;
        while(i!=a.length() && j!=b.length()){
            if(a[i]==b[j]){
                i++;
                j++;
            }else{
                if(poss){
                    i++;
                    poss=false;
                }
                else return false;
            }
        }
        return true;
    }
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        int maxi=1;
        sort(words.begin(),words.end(),[](string &a,string &b){
            return a.length()<b.length();
        });
        vector<int> dp(n,1);
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(compare(words[i],words[j]) && dp[j]+1>dp[i]){
                    dp[i]=dp[j]+1;
                }
            }
            maxi=max(maxi,dp[i]);
        }
        return maxi;
    }
};