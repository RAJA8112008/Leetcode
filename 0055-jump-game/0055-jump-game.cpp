class Solution {
public:
 bool solve(vector<int>&nums,int idx,int&size,vector<int>&dp){
    if(idx>=size-1)return true;
    if(dp[idx]!=-1)return dp[idx];

    for(int i=1;i<=nums[idx];i++){
        if(solve(nums,idx+i,size,dp)==true)return dp[i]= true;
    }
    return dp[idx]=false;
 }
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return solve(nums,0,n,dp);
    }
};