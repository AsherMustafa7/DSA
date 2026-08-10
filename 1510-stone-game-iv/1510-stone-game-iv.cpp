class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> dp(n + 1, false);

        // dp[i] = true means the player whose turn it is
        // can force a win with i stones.

        for (int i = 1; i <= n; i++) {

            for (int j = 1; j * j <= i; j++) {

                // Take j*j stones.
                // If the opponent loses from the remaining stones,
                // then the current player wins.
                if (dp[i - j * j] == false) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};