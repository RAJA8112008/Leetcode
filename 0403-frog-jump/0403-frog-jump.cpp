class Solution {
public:
    bool solve(vector<int>& stones,int curr_idx,int prevjump,unordered_map<int,int>&mp,vector<vector<int>>&dp){
        if(curr_idx==stones.size()-1)return true;
        if(dp[curr_idx][prevjump]!=-1)return dp[curr_idx][prevjump];
        //find all jumps 
        for(int nextjump=prevjump-1;nextjump<=prevjump+1;nextjump++){
            if(nextjump <= 0) continue;
            
            int nextstone=stones[curr_idx]+nextjump;
            //find this exits in Stones or not 
            if(mp.find(nextstone)!=mp.end()){
                int nextidx = mp[nextstone];

                // Continue from this stone
                if(solve(stones, nextidx, nextjump, mp,dp))
                    return dp[curr_idx][prevjump]=true;
            }
        }
        return dp[curr_idx][prevjump] = 0;
    }
    bool canCross(vector<int>& stones) {
        int n=stones.size();
        if(stones[1]!=1)return false;
        unordered_map<int,int>mp;
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        for(int i=0;i<n;i++){
            mp[stones[i]]=i;
        }
        int currStoneidx=0;
        int prevjump=0;
        return solve(stones,currStoneidx,prevjump,mp,dp);
    }
};