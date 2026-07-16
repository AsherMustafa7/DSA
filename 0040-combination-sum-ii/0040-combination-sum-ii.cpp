class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans;
        vector<int> curr;

        solve(candidates, target, 0, curr, ans);

        return ans;
    }

    void solve(vector<int>& candidates, int target, int index,vector<int>& curr, vector<vector<int>>& ans)
    {
        if(target == 0)
        {
            ans.push_back(curr);
            return;
        }

        for(int i = index; i < candidates.size(); i++)
        {
            // Skip duplicates
            if(i > index && candidates[i] == candidates[i - 1])
                continue;

            // Since array is sorted, no need to continue
            if(candidates[i] > target)
                break;

            curr.push_back(candidates[i]);

            // Move to next index because each number can be used once
            solve(candidates, target - candidates[i], i + 1, curr, ans);

            curr.pop_back();
        }
        
    }
};