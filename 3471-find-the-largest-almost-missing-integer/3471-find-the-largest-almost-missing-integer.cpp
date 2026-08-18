class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        // {count, value}
        vector<pair<int, int>> freq(n);

        for (int i = 0; i < n; i++) {
            freq[i] = {0, nums[i]};
        }

        // k size window
        int i = 0;
        int j = k - 1;

        while (j < n) {

            // values already counted in this window
            unordered_set<int> seen;

            for (int l = i; l <= j; l++) {

                int val = nums[l];

                // Don't count same value twice
                // in the same window
                if (seen.count(val)) {
                    continue;
                }

                seen.insert(val);

                // Find value in freq
                for (int x = 0; x < n; x++) {
                    if (freq[x].second == val) {
                        freq[x].first++;
                        break;
                    }
                }
            }

            // Move window
            i++;
            j++;
        }

        // Find largest value appearing in exactly one window
        int ans = -1;

        for (int i = 0; i < n; i++) {
            if (freq[i].first == 1) {
                ans = max(ans, freq[i].second);
            }
        }
        return ans;
    }
};