class Solution {
public:
int solve(int n,vector<int>&dp){
    if(n==0)return 1;//reached at the top so one path 
    if(n<0)return 0;//not reach at the top 
    if(dp[n]!=-1)return dp[n];
    return dp[n]=solve(n-1,dp)+solve(n-2,dp);
}
    int climbStairs(int n) {
        //using memoization 
        vector<int>dp(n+1,-1);
        return solve(n,dp);
    }
};