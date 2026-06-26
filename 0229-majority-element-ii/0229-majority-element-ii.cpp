class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        //first store freq 
        vector<int>ans;
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        //search if freq is more then n/3 
        for(auto val:mp){
            if(val.second>n/3){
                ans.push_back(val.first);
            }
        }
        return ans;
    }
};