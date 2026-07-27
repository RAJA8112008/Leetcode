class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxval=INT_MIN;
        for(int i=0;i<nums.size()-1;i++){
            for(int j=i+1;j<nums.size();j++){
                int  prod=(nums[i]-1)*(nums[j]-1);
                maxval=max(maxval,prod);
            }
        }
        return maxval;
    }
};