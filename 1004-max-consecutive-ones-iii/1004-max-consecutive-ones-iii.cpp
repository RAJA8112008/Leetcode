
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i = 0;
        int j = 0;
        int n = nums.size();
        int maxLen = 0;
        int count = k;

        while (j < n) {
            if (nums[j] == 0) {
                k--;
            }
            while (k < 0) {
                if (nums[i] == 0) {
                    k++;
                }
                i++;
            }

            maxLen = max(maxLen, j - i + 1);
            j++;
        }

        return maxLen;
    }
};
