class Solution {
public:
  string shortestBeautifulSubstring(string s, int k) {
    vector<pair<int, string>> ans;

    for (int i = 0; i < s.length(); i++) {
        int j = i;
        string word = "";
        int count = 0;

        while (j < s.length() && count != k) {

            cout << "Char is --> " << s[j] << endl;

            if (s[j] == '1') {
                count++;
            }

            word += s[j];
            j++;
        }

        // Only store substrings having exactly k ones
        if (count == k) {
            ans.push_back({(int)word.length(), word});
        }
    }
    sort(ans.begin(), ans.end());

    if (ans.empty()) {
        return "";
    }
    return ans[0].second;
}

};