class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int n = nums.size();

        if(n < 3)
            return 0;

        vector<pair<int,int>> freq;

        for(int i = 0; i < n; i++) {
            freq.push_back({nums[i], i});
        }

        sort(freq.begin(), freq.end());

        int count = 0;

        int i = 0;

        while(i < n) {
            int j = i;

            // Find all occurrences of same value
            while(j < n && freq[j].first == freq[i].first) {
                j++;
            }

            // Only exactly 3 occurrences
            if(j - i == 3) {
                int a = freq[i].second;
                int b = freq[i + 1].second;
                int c = freq[i + 2].second;

                if(b - a == c - b) {
                    count++;
                }
            }

            i = j;
        }

        return count;
    }
};