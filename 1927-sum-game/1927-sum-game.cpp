class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int mid = n / 2;

        int alicesum = 0;
        int bobsum = 0;

        int aliceQ = 0;
        int bobQ = 0;

        for (int i = 0; i < mid; i++) {
            if (num[i] == '?')
                aliceQ++;
            else
                alicesum += num[i] - '0';
        }

        for (int i = mid; i < n; i++) {
            if (num[i] == '?')
                bobQ++;
            else
                bobsum += num[i] - '0';
        }

        int diff = alicesum - bobsum;

        if ((aliceQ + bobQ) % 2 == 1)
            return true;

        return diff != (bobQ - aliceQ) * 9 / 2;
    }
};