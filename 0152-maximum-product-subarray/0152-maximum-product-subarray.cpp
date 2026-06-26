class Solution {
public:
    int maxProduct(vector<int>& nums) {
       int minans=nums[0];
       int maxans=nums[0];
       int ans=nums[0];
       for(int i=1;i<nums.size();i++){
        if(nums[i]<0)swap(minans,maxans);
        maxans=max(nums[i],maxans*nums[i]);
        minans=min(nums[i],minans*nums[i]);
        ans=max(ans,maxans);
       } 
       return ans;
    }
};