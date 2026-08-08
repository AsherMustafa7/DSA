class Solution {
public:

    // factor contribution of each digit
    //        2 3 5 7
    // 1 ->   0 0 0 0
    // 2 ->   1 0 0 0
    // 3 ->   0 1 0 0
    // 4 ->   2 0 0 0
    // 5 ->   0 0 1 0
    // 6 ->   1 1 0 0
    // 7 ->   0 0 0 1
    // 8 ->   3 0 0 0
    // 9 ->   0 2 0 0

    int A, B, C, D;
    vector<int> memo;

    int id(array<int,4> r) {
        return (((r[0] * (B + 1) + r[1]) * (C + 1) + r[2])
                * (D + 1) + r[3]);
    }

    array<int,4> factors(int d) {
        static int f[10][4] = {
            {0,0,0,0},
            {0,0,0,0},
            {1,0,0,0},
            {0,1,0,0},
            {2,0,0,0},
            {0,0,1,0},
            {1,1,0,0},
            {0,0,0,1},
            {3,0,0,0},
            {0,2,0,0}
        };

        return {f[d][0], f[d][1], f[d][2], f[d][3]};
    }

    // Remove the contribution of digit d from required factors.
    array<int,4> removeFactors(array<int,4> r, int d) {
        auto f = factors(d);

        for(int i = 0; i < 4; i++)
            r[i] = max(0, r[i] - f[i]);

        return r;
    }

    // Minimum number of digits required to satisfy r.
    int minDigits(array<int,4> r) {

        int idx = id(r);

        if(memo[idx] != -1)
            return memo[idx];

        if(r[0] == 0 && r[1] == 0 &&
           r[2] == 0 && r[3] == 0)
            return memo[idx] = 0;

        int ans = 1e9;

        // Digit 1 doesn't help satisfy any requirement,
        // so we don't need to consider it here.
        for(int d = 2; d <= 9; d++) {

            auto nr = removeFactors(r, d);

            // Make sure the state actually changed.
            if(nr != r) {
                ans = min(ans, 1 + minDigits(nr));
            }
        }

        return memo[idx] = ans;
    }

    // Construct the lexicographically smallest string of
    // exactly len digits satisfying the remaining requirement.
    string build(int len, array<int,4> r) {

        string ans;

        for(int pos = 0; pos < len; pos++) {

            int remaining = len - pos - 1;

            for(int d = 1; d <= 9; d++) {

                auto nr = removeFactors(r, d);

                // Can the remaining positions satisfy everything?
                if(minDigits(nr) <= remaining) {

                    ans += char('0' + d);
                    r = nr;
                    break;
                }
            }
        }

        return ans;
    }

    string smallestNumber(string num, long long t) {

        // ------------------------------------------------
        // STEP 1: Factor t into 2, 3, 5, 7
        // ------------------------------------------------

        A = B = C = D = 0;

        long long x = t;

        while(x % 2 == 0) {
            A++;
            x /= 2;
        }

        while(x % 3 == 0) {
            B++;
            x /= 3;
        }

        while(x % 5 == 0) {
            C++;
            x /= 5;
        }

        while(x % 7 == 0) {
            D++;
            x /= 7;
        }

        // If anything remains, it has a prime factor
        // other than 2,3,5,7.
        if(x != 1)
            return "-1";


        // ------------------------------------------------
        // STEP 2: DP initialization
        // ------------------------------------------------

        int totalStates =
            (A + 1) *
            (B + 1) *
            (C + 1) *
            (D + 1);

        memo.assign(totalStates, -1);


        array<int,4> need = {A,B,C,D};


        // ------------------------------------------------
        // STEP 3: Is num itself already valid?
        // ------------------------------------------------

        array<int,4> remaining = need;

        bool zero = false;

        for(char ch : num) {

            int d = ch - '0';

            if(d == 0) {
                zero = true;
                break;
            }

            remaining = removeFactors(remaining, d);
        }

        if(!zero &&
           remaining[0] == 0 &&
           remaining[1] == 0 &&
           remaining[2] == 0 &&
           remaining[3] == 0) {

            return num;
        }


        // ------------------------------------------------
        // STEP 4:
        // Try to find the smallest number with SAME length
        // that is greater than num.
        // ------------------------------------------------

        int n = num.size();

        // prefix[i] = factors supplied by num[0 ... i-1]
        vector<array<int,4>> prefix(n + 1);

        prefix[0] = {0,0,0,0};

        vector<bool> hasZero(n + 1, false);

        for(int i = 0; i < n; i++) {

            prefix[i + 1] = prefix[i];

            int d = num[i] - '0';

            if(d == 0) {
                hasZero[i + 1] = true;
            }
            else {
                auto f = factors(d);

                for(int j = 0; j < 4; j++)
                    prefix[i + 1][j] += f[j];
            }

            hasZero[i + 1] =
                hasZero[i + 1] || hasZero[i];
        }


        // Try changing a position.
        //
        // We go from RIGHT to LEFT because we want
        // to change the latest possible digit.
        for(int i = n - 1; i >= 0; i--) {

            // Prefix must remain exactly the same,
            // therefore it cannot contain zero.
            if(hasZero[i])
                continue;

            int originalDigit = num[i] - '0';

            // We need a digit strictly greater than num[i].
            for(int d = originalDigit + 1; d <= 9; d++) {

                auto r = need;

                // Remove factors supplied by prefix.
                for(int j = 0; j < 4; j++) {
                    r[j] = max(0, r[j] - prefix[i][j]);
                }

                // Remove current candidate digit.
                r = removeFactors(r, d);

                int suffixLength = n - i - 1;

                // Can the suffix satisfy the remaining requirements?
                if(minDigits(r) <= suffixLength) {

                    string answer = num.substr(0, i);

                    answer += char('0' + d);

                    answer += build(suffixLength, r);

                    return answer;
                }
            }
        }


        // ------------------------------------------------
        // STEP 5:
        // No solution with the same length.
        //
        // So we need a longer number.
        // ------------------------------------------------

        int requiredDigits = minDigits(need);

        int newLength = max(n + 1, requiredDigits);

        return build(newLength, need);
    }
};