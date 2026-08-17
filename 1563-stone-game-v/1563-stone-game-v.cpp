class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {

        int n = stoneValue.size();

        // prefix[i] = sum of stoneValue[0 ... i-1]
        vector<int> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + stoneValue[i];
        }

        // dp[l][r] = maximum score Alice can get
        // from subarray l...r
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // length >= 2
        for (int len = 2; len <= n; len++) {

            for (int l = 0; l + len - 1 < n; l++) {

                int r = l + len - 1;

                // Try every possible split
                for (int k = l; k < r; k++) {

                    // Sum of left part
                    int leftSum = prefix[k + 1] - prefix[l];

                    // Sum of right part
                    int rightSum = prefix[r + 1] - prefix[k + 1];

                    if (leftSum < rightSum) {

                        // Bob throws away right.
                        // Alice keeps left and gets leftSum.
                        // Continue playing on left.
                        dp[l][r] = max(
                            dp[l][r],
                            leftSum + dp[l][k]
                        );
                    }
                    else if (rightSum < leftSum) {

                        // Bob throws away left.
                        // Alice keeps right and gets rightSum.
                        // Continue playing on right.
                        dp[l][r] = max(
                            dp[l][r],
                            rightSum + dp[k + 1][r]
                        );
                    }
                    else {

                        // Equal sums.
                        // Alice can choose either side.
                        dp[l][r] = max(
                            dp[l][r],
                            leftSum + dp[l][k]
                        );

                        dp[l][r] = max(
                            dp[l][r],
                            rightSum + dp[k + 1][r]
                        );
                    }
                }
            }
        }

        return dp[0][n - 1];
    }
};