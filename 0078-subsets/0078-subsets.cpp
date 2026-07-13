class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<vector<int>>vf;
        vector<int>v;
        fp(vf,nums,0,v);
        return vf;
    }
    void fp(vector<vector<int>>&vf,vector<int>& nums,int i, vector<int>v)
    {
        
        if(i==nums.size())
        {
            vf.push_back(v);
            return;
        }
        
        v.push_back(nums[i]);
        fp(vf,nums,i+1,v);
        v.pop_back();
        fp(vf,nums,i+1,v);
    }
};