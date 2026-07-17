class Solution {
public:

    void solve(int index, int k, int n, vector<vector<int>> & ans, vector<int>& ds){
        if(ds.size() == k){
            if(n == 0){
                ans.push_back(ds);
                return;
            }
        }
        if(n < 0) return;
        for(int i=index; i<=9; i++){
            ds.push_back(i);
            solve(i+1, k, n-i, ans, ds);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> ds;
        solve(1, k, n, ans, ds);
        return ans;
    }
};