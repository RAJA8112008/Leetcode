class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxone=INT_MIN;
        int one=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                one++;
            }else{
                maxone=max(maxone,one);
                one=0;
            }
        }
        maxone=max(maxone,one);
        return maxone;
    }
};