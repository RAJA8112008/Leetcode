class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length())return false;
        unordered_map<char,int>mp;
        //first store each char in map of s 
        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
        }
        //remove char from map storing char of t 
        for(int i=0;i<t.length();i++){
            mp[t[i]]--;
        }
        for(auto val:mp){
            if(val.second!=0)return false;
        }
        return true;
    }
};