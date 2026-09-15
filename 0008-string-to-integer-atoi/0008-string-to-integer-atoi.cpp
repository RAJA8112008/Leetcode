class Solution {
public:
    int myAtoi(string s) {
        int n = s.length();
        int i = 0;

        // Remove leading spaces
        while (i < n && s[i] == ' ') {
            i++;
        }

        // Check sign
        bool negsign = false;

        if (i < n && s[i] == '-') {
            negsign = true;
            i++;
        }
        else if (i < n && s[i] == '+') {
            i++;
        }

        long long num = 0;

        // Read digits
        while (i < n && isdigit(s[i])) {

            int digit = s[i] - '0';

            // Check overflow
            if (num > (INT_MAX - digit) / 10) {
                if (negsign)
                    return INT_MIN;
                else
                    return INT_MAX;
            }

            num = num * 10 + digit;
            i++;
        }

        if (negsign) {
            num = -num;
        }

        return (int)num;
    }
};