class Solution {
public:
    static const int MOD = 1000000007;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();

        vector<int> digits;
        vector<int> pos;

        // Store non-zero digits and their positions
        for (int i = 0; i < n; i++) {
            if (s[i] != '0') {
                digits.push_back(s[i] - '0');
                pos.push_back(i);
            }
        }

        int m = digits.size();

        // prefix sum of digits
        vector<long long> prefSum(m + 1, 0);

        // prefix concatenated number
        vector<long long> prefNum(m + 1, 0);

        // powers of 10
        vector<long long> pow10(m + 1, 1);

        for (int i = 0; i < m; i++) {
            prefSum[i + 1] = prefSum[i] + digits[i];
            prefNum[i + 1] = (prefNum[i] * 10 + digits[i]) % MOD;
            pow10[i + 1] = (pow10[i] * 10) % MOD;
        }

        vector<int> ans;

        for (auto &q : queries) {

            int l = q[0];
            int r = q[1];

            // first non-zero >= l
            auto it1 = lower_bound(pos.begin(), pos.end(), l);

            // first non-zero > r
            auto it2 = upper_bound(pos.begin(), pos.end(), r);

            if (it1 == it2) {
                ans.push_back(0);
                continue;
            }

            int L = it1 - pos.begin();
            int R = (it2 - pos.begin()) - 1;

            long long sum = prefSum[R + 1] - prefSum[L];

            int len = R - L + 1;

            long long num =
                (prefNum[R + 1] -
                 (prefNum[L] * pow10[len]) % MOD +
                 MOD) % MOD;

            ans.push_back((num * sum) % MOD);
        }

        return ans;
    }
};