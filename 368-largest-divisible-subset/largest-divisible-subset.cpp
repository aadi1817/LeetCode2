class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& arr) {
        int n=arr.size();
        vector<int> dp(n,1);
        vector<int> hash(n);
        sort(arr.begin(),arr.end());
        int ans=1;
        int lastindex=0;
        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int j=0;j<i;j++){
                if(arr[i]%arr[j]==0 && dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                    hash[i]=j;
                }
            }
            if(ans<dp[i]){
                ans=dp[i];
                lastindex=i;
            }
        }
        vector<int> temp;
        temp.push_back(arr[lastindex]);
        while(hash[lastindex]!=lastindex){
            lastindex=hash[lastindex];
            temp.push_back(arr[lastindex]);
        }
        reverse(temp.begin(),temp.end());
        return temp;
    }
};