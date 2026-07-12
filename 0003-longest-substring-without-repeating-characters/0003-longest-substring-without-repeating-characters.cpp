class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mp;
        int curr=0;
        int maxcurr=0;
        for(int i=0;i<s.length();i++){
            char ch=s[i];
            if(mp.find(ch)!=mp.end()){
                curr=max(curr,mp[ch]+1);
            }
            mp[ch]=i;
            maxcurr=max(maxcurr,i-curr + 1);
        }
        return maxcurr;
    }
};