class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //using map 
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        for(auto val:mp){
            if(val.second>nums.size()/2)return val.first;
        }
        return -1;
    }
};