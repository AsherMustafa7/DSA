class Solution {
public:
    int missingInteger(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());

        int sum = nums[0];

        // Find the sum of the longest consecutive prefix
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1] + 1) {
                sum += nums[i];
            } else {
                break;
            }
        }

        // Find smallest integer >= sum that is not in nums
        while (st.find(sum) != st.end()) {
            sum++;
        }

        return sum;
    }
};