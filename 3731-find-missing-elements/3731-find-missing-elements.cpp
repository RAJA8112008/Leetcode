class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
      int n=nums.size();
    int low=nums[0];
    int high=nums[n-1];

//create a 
unordered_map<int,int>mp;
//push values with zero 
for(int i=low;i<=high;i++){
    mp[i]=0;
}
//update freq 
for(auto x:nums){
    mp[x]=1;
}
//travese non map 
vector<int>ans;
for(auto val:mp){
    if(val.second==0){
        ans.push_back(val.first);
    }
}
sort(ans.begin(),ans.end());
return ans;
    }
};