class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
       vector<vector<int>>ans;
       sort(nums.begin(),nums.end());
       int n=nums.size();
       for(int i=0;i<n-3;i++){
        if(i>0 && nums[i]==nums[i-1])continue;
        for(int j=i+1;j<n-2;j++){
            //two pointer proble 
            int k=j+1;
            int l=n-1;
            //remove duplicacy 
            if(j>i+1 && nums[j]==nums[j-1])continue;
            while(k<l){
               long long  sum=1LL*nums[k]+nums[l]+nums[i]+nums[j];
                if(sum==target){
                    ans.push_back({nums[i],nums[j],nums[k],nums[l]});
                    k++;
                    l--;
                    //remove duplicacy 
                    while(k<l &&nums[k]==nums[k-1])k++;
                    while(k<l &&nums[l]==nums[l+1])l--;
                }else if(sum<target){
                    k++;
                }else{
                    l--;
                }
            }
        }
       }
      return ans;

    }
};