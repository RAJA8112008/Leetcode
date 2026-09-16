class Solution {
public:
    int firstUniqChar(string s) {
        vector<pair<int,int>>freq;
        if(s.length()==1 ||(s.length()==2 && s[0]!=s[1]  ))return 0;
        int ans=INT_MAX;
        for(int i=0;i<s.length();i++){
            freq.push_back({s[i],i});
        }
        sort(freq.begin(),freq.end());
        for(int i=0;i<freq.size();i++){
        bool leftSame = (i > 0 && freq[i].first == freq[i-1].first);
        bool rightSame = (i + 1 < freq.size() && freq[i].first == freq[i+1].first);

        if(!leftSame && !rightSame) {
            ans = min(ans, freq[i].second);
        }
        }
        return ans==INT_MAX ?-1:ans;
    }
};