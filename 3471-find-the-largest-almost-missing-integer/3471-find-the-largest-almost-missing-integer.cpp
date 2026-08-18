class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {

        unordered_map<int, int> count;

        int n = nums.size();

        // Check every subarray of size k
        for (int i = 0; i <= n - k; i++) {

            unordered_set<int> seen;

            for (int j = i; j < i + k; j++) {
                seen.insert(nums[j]);
            }

            // Each number in this window appears in exactly
            // one subarray (this current window)
            for (int x : seen) {
                count[x]++;
            }
        }

        int ans = -1;

        // Find the largest number appearing in exactly one window
        for (auto &[x, freq] : count) {
            if (freq == 1) {
                ans = max(ans, x);
            }
        }

        return ans;
    }
};