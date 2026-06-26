class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        //first sort
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++){
            //now using two pointer 
            int j=i+1;
            int k=n-1;
            //ignore duplacy here for i 
            if(i>0 && nums[i]==nums[i-1])continue;
            while(j<k){
                int sum=nums[j]+nums[k]+nums[i];
                if(sum==0){
                    ans.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                    //ignore duplacy 
                   while(j<k && nums[j]==nums[j-1])j++;
                   while( j<k && nums[k]==nums[k+1])k--;
                }else if(sum<0){
                    j++;
                }else{
                    k--;
                }
            }
        }
        return ans;
    }
};