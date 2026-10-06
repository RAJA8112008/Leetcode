class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();

        if (n == 1)
            return true;

        int maxidx = 0;
        int curridx = 0;

        while (curridx < n) {

            maxidx = max(maxidx, curridx + nums[curridx]);

            if (maxidx >= n - 1)
                return true;

            if (curridx == maxidx)
                return false;

            curridx++;
        }

        return false;
    }
};