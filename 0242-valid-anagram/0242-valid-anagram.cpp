class Solution {
public:
    bool isAnagram(string s, string goal) {
         if(s.length()!=goal.length())return false;
        unordered_map<char,int>mp;
        for(auto ch:s){
            mp[ch]++;
        }
        //again travese 
        for(auto ch:goal){
            if(mp.find(ch)!=mp.end()){
                mp[ch]--;
            }
        }
        for(auto c:mp){
            if(c.second!=0)return false;
        }
        return true;
    }
};