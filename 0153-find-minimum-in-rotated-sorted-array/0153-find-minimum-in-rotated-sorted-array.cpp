class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int st=0;
        int ed=n-1;
        int ans=INT_MAX;
        while(st<=ed){
            int mid=st+(ed-st)/2;
            if(nums[st]<=nums[mid]){
                ans=min(ans,nums[st]);
                st=mid+1;
            }else{
                ans=min(ans,nums[mid]);
                ed=mid-1;
            }
        }
        return ans;
    }
};