class Solution {
public:
    int maxPalindromes(string s, int k) 
    {
        int n = s.size();

        // dp[i][j] = true if s[i...j] is a palindrome
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        // Find all palindromes
        for(int i = n - 1; i >= 0; i--)
        {
            for(int j = i; j < n; j++)
            {
                if(s[i] == s[j] && (j - i <= 1 || dp[i + 1][j - 1]))
                {
                    dp[i][j] = true;
                }
            }
        }

        // dpEnd[i] = maximum number of palindromes
        // we can select from s[0...i]
        vector<int> dpEnd(n + 1, 0);

        for(int i = 1; i <= n; i++)
        {
            // Don't take a palindrome ending at i-1
            dpEnd[i] = dpEnd[i - 1];

            // Try every palindrome [j, i-1]
            for(int j = 0; j < i; j++)
            {
                if(i - j >= k && dp[j][i - 1])
                {
                    dpEnd[i] = max(dpEnd[i], dpEnd[j] + 1);
                }
            }
        }

        return dpEnd[n];
    }
};