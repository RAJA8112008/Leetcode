class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {

        // Store {value, original index}
        vector<pair<int, int>> lexiarr;

        for (int i = 0; i < nums.size(); i++) {
            lexiarr.push_back({nums[i], i});
        }

        // Sort by value
        sort(lexiarr.begin(), lexiarr.end());

        int n = nums.size();

        // Find every group
        int start = 0;

        while (start < n) {

            int end = start;

            // Keep adding while adjacent values can be connected
            while (end + 1 < n &&
                   lexiarr[end + 1].first - lexiarr[end].first <= limit) {
                end++;
            }

            // Now [start ... end] is one connected component

            vector<int> indices;
            vector<int> values;

            for (int j = start; j <= end; j++) {
                values.push_back(lexiarr[j].first);
                indices.push_back(lexiarr[j].second);
            }

            // Put smallest values at smallest indices
            sort(indices.begin(), indices.end());

            for (int j = 0; j < indices.size(); j++) {
                nums[indices[j]] = values[j];
            }

            // Move to next group
            start = end + 1;
        }

        return nums;
    }
};