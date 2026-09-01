class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=1;
         int elem=nums[0];
        for(int i=1;i<nums.size();i++){
            if(elem==nums[i]){
                count++;
            }else{
                count--;
                if(count==0){
                    elem=nums[i+1];
                }
            }
        }
        return elem;
    }
};