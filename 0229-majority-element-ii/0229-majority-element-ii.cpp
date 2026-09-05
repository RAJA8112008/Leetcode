class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1=0;
        int maj1=0;
        int count2=0;
        int maj2=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==maj1){
                count1++;
            }else if(nums[i]==maj2){
                count2++;
            }else if(count1==0){
                count1++;
                maj1=nums[i];
            }else if(count2==0){
                count2++;
                maj2=nums[i];
            }else{
                count1--;
                count2--;
            }
        }
        vector<int>ans;
        int c1=0;
        int c2=0;
        for(auto val:nums){
            if(val==maj1){
                c1++;
            }else if(val==maj2){
                c2++;
            }
        }
        if(c1>nums.size()/3){
            ans.push_back(maj1);
        }
         if(c2>nums.size()/3){
            ans.push_back(maj2);
        }
        return ans;
    }
};