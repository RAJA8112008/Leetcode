class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char,int> mp;
        int n = s.length();
        int ans = INT_MIN;

        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {

                // check char exists or not
                if(mp.find(s[j]) != mp.end()) {

                    if(mp[s[j]] < 2) {
                        mp[s[j]]++;
                    }
                    else {
                        // frequency is already 2
                        break;
                    }
                }
                else {
                    mp[s[j]]++;
                }

                // update length
                ans = max(ans, j - i + 1);
            }

            // clear map for next i
            mp.clear();
        }

        return ans;
    }
};