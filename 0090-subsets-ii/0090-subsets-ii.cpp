class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>v;
        subpum(nums,ans,v,0);
        return ans;
    }
    void subpum(vector<int>& nums,vector<vector<int>>&ans,vector<int>v, int index)
    {
        
            ans.push_back(v);
           
        for(int i =index; i <nums.size();i++)
        {
            if(i>index && nums[i]==nums[i-1])
            {
                continue;
            }
            v.push_back(nums[i]);
            subpum(nums,ans,v,i+1);// take 
            v.pop_back();
            
        }
    }
};