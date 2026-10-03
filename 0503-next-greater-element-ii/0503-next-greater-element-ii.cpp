class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int>ans;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int val=nums[i];
            bool find=false;
            int j=i;
             while(j<i+n){
               if(val<nums[j%n]){
                  find=true;
                 ans.push_back(nums[j%n]);
                 break;
               }
               j++;
            }
            if(find==false){
                ans.push_back(-1);
            }
            
        }
       return ans;
    }
};