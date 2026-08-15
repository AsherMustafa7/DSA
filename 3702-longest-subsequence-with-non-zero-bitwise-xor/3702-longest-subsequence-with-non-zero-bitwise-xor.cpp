class Solution {
public:
    int longestSubsequence(vector<int>& nums) {

        int xr = 0;
        bool nonZero = false;

        for (int x : nums) {
            xr ^= x;

            if (x != 0)
                nonZero = true;
        }

        // Entire array has non-zero XOR
        if (xr != 0)
            return nums.size();

        // Entire array XOR is 0, but there is a non-zero element.
        // Remove that element -> remaining XOR becomes that element.
        if (nonZero)
            return nums.size() - 1;

        // Every element is 0, so every subsequence has XOR 0.
        return 0;
    }
};