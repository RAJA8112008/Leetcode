class Solution {
public:
int solve(vector<int>&nums,int i,int ed,vector<int>&dp){
    if(i>ed)return 0;
    if(dp[i]!=-1)return dp[i];
    //include 
    int include=nums[i]+solve(nums,i+2,ed,dp);
    //exclude 
    int exclude=solve(nums,i+1,ed,dp);
    return dp[i]= max(include,exclude);
}
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp1(n+1,-1);
        vector<int>dp2(n+1,-1);
        //case 1
        if(n==1)return nums[0];
        int ed=solve(nums,1,n-1,dp1);
        int start=solve(nums,0,n-2,dp2);
        //case 2
     
        return max(start,ed);
    }
};