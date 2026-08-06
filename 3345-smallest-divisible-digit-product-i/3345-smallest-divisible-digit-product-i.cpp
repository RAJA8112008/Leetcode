class Solution {
public:
    int smallestNumber(int n, int t) {
        for (int i = n; ; i++) {
            int digitSum = 1;
            int temp = i;   // Store original value

            while (temp > 0) {
                int digit = temp % 10;
                digitSum *= digit;
                temp = temp / 10;
            }

            if (digitSum % t == 0) {
                return i;   // Return original i
            }
        }
        return -1;
    }
};