class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> vec;
        vector<int> v;
        solve(candidates,target,0,v,0,vec);
        return vec;
    }
    void solve(vector<int> candidates,int target,int index, vector<int> &v,int sum, vector<vector<int>> &vec)
    {
        if(index== candidates.size() )
        {
            if(sum==target)
                vec.push_back(v);
                return;
        }
        if(sum>target)
        {
            return;
        }
        
        v.push_back(candidates[index]);
        solve(candidates,target,index,v,sum+candidates[index],vec);
        v.pop_back();
        solve(candidates,target,index+1,v,sum,vec);
    }
};