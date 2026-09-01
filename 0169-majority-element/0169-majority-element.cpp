class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //brute force 
        unordered_map<int,int>mp;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        for(auto val:mp){
            if(val.second>n/2)return val.first;
        }
        return 0;
    }
};