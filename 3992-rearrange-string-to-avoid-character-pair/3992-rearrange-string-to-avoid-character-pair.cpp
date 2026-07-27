class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        unordered_map<int,int>mp;
        //store in map 
        string ans="";
        for(auto val:s){
            mp[val-'a']++;
        }
        //if y is in map then 
        if(mp.find(y-'a')!=mp.end()){
            while(mp[y-'a']!=0){
                ans+=y;
                mp[y-'a']--;
            }
        }
        if(mp.find(x-'a')!=mp.end()){
            while(mp[x-'a']!=0){
                ans+=x;
                 mp[x-'a']--;
            }
        }
        //traverse on map 
        for(auto val:mp){
            while(val.second!=0){
                ans+=(val.first+'a');
                val.second--;
            }
        }
        return ans;
    }
};