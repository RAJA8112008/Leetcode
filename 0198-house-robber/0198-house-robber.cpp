class Solution {
public:
int solve(int i,vector<int>&nums,vector<int>&dp){
    int n=nums.size();
    if(i>=n)return 0;
    if(dp[i]!=-1)return dp[i];
    //include 
    int include=nums[i]+solve(i+2,nums,dp);
    //exclude 
    int exclude=solve(i+1,nums,dp);
    return dp[i]=max(include,exclude);
}
    int rob(vector<int>& nums) {
        int i=0;
        int n=nums.size();
        vector<int>dp(n+1,-1);
        return solve(i,nums,dp);
    }
};