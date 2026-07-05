class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int>mp{{'I', 1},{'V', 5},{'X', 10},{'L', 50},{'C', 100},{'D', 500},{'M', 1000}};
        int ans=0;
        for(int i=0;i<s.length();i++){
            int first=mp[s[i]];
            int second=mp[s[i+1]];
            if(second>first){
             ans-=first;
            }else{
                ans+=first;
            }
        }
        return ans;
    }
};