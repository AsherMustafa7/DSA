class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> p;

        for (int number = 0; number < (1 << n); number++) {
            vector<int> q; 

           
            for (int i = 0; i < n; i++) {
                
                
                if (number & (1 << i)) {
                    q.push_back(nums[i]);
                }
            }
            p.push_back(q); 
        }
        return p;
    }
};