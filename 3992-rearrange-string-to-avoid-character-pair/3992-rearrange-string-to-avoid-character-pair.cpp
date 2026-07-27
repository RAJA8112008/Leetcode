class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        unordered_map<char,int>mp;
        //store in map 
        string ans="";
        for(auto val:s){
            mp[val]++;
        }
        //if y is in map then 
        if(mp.find(y)!=mp.end()){
            while(mp[y]!=0){
                ans+=y;
                mp[y]--;
            }
        }
        if(mp.find(x)!=mp.end()){
            while(mp[x]!=0){
                ans+=x;
                 mp[x]--;
            }
        }
        //traverse on map 
        for(auto val:mp){
            while(val.second!=0){
                ans+=(val.first);
                val.second--;
            }
        }
        return ans;
    }
};