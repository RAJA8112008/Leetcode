class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0;
        int j=0;
        int n=nums.size();
        int len=INT_MAX;
        int sum=0;
        //travese on array
        while(j<n){
            sum+=nums[j];
            while(sum>=target){
                //strore len 
                len=min(len,j-i+1);
                //move left to next;
                sum-=nums[i];
                i++;
            }
            j++;
            
        }
        if(len==INT_MAX)return 0;
        return len;
    }
};