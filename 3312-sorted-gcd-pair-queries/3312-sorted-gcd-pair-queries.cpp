class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx = *max_element(nums.begin(), nums.end());

        // Frequency of each value
        vector<long long> freq(mx + 1, 0);
        for (int x : nums)
            freq[x]++;

        // pairs[d] = pairs where both numbers are divisible by d
        vector<long long> pairs(mx + 1, 0);

        for (int d = 1; d <= mx; d++) {
            long long cnt = 0;

            for (int multiple = d; multiple <= mx; multiple += d)
                cnt += freq[multiple];

            pairs[d] = cnt * (cnt - 1) / 2;
        }

        // exact[d] = number of pairs having gcd exactly d
        vector<long long> exact(mx + 1, 0);

        for (int d = mx; d >= 1; d--) {
            exact[d] = pairs[d];

            for (int multiple = 2 * d; multiple <= mx; multiple += d)
                exact[d] -= exact[multiple];
        }

        // Prefix sums
        vector<long long> prefix(mx + 1, 0);

        for (int i = 1; i <= mx; i++)
            prefix[i] = prefix[i - 1] + exact[i];

        // Answer queries
        vector<int> ans;
        for (long long q : queries) {
            int g = lower_bound(prefix.begin(), prefix.end(), q + 1) - prefix.begin();
            ans.push_back(g);
        }

        return ans;
    }
};