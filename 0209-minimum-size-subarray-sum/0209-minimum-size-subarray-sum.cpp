class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        int mini=INT_MAX;
        int j=0;
        for(int i=0;i<n;i++){
           
            //till sum is small then target val 
            while(j<n && sum<target){
                sum+=nums[j];
                  j++;
            }

            //while 
            if(sum>=target){
                //update mini 
                mini=min(mini,j-i);
            }
            //move i right 
            sum-=nums[i];
        }
        return mini==INT_MAX?0:mini;
    }
};