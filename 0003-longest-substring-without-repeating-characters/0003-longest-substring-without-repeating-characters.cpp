class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        int i=0;
        unordered_map<char,int>mp;
        int j=0;
        int maxLen=0;
        while(j<n){
            char ch=s[j];
           while(mp[ch]>0){
                mp[s[i]]--;
                 i++;
           }
           maxLen=max(maxLen,j-i+1);
           mp[ch]++;
           j++;
        }
        return maxLen;
    }
};