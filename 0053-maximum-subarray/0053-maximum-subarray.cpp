class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //brute force 
        int i=0;
        int n=nums.size();
        if(n==1)return nums[0];
        int maxsum=INT_MIN;
        int sum=0;
        for(int i=0;i<n;i++){
          sum+=nums[i];
           if(sum<0){
            sum=0;
           }

           maxsum=max(maxsum,sum);
        }
        return maxsum==0?*max_element(nums.begin(),nums.end()):maxsum;
    }
};