class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> frq;
        for(auto x:nums){
            frq[x]++;
        }
        if(k==n){
            return *max_element(nums.begin(),nums.end());
        }
        if(k==1){
            int ans=-1;
            for(auto it:frq){
                if(it.second==1) ans=max(ans,it.first);
            }
            return ans;
        }
        if(frq[nums[0]]==1 && frq[nums[n-1]]==1) return max(nums[0],nums[n-1]);
        else if(frq[nums[0]]!=1 && frq[nums[n-1]]==1) return nums[n-1];
        else if(frq[nums[n-1]]!=1 && frq[nums[0]]==1) return nums[0];

        return -1;  
    }
};