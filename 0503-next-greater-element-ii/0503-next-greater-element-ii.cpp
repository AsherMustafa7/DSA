class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) 
    {
        int p=0;
        vector<int>v;
        for(int i =0;i<nums.size() ;i++)
        {   int j=0;
            for(j=0;j<nums.size();j++)
            {
                if(nums[(j+i+1)%nums.size()]>nums[i])
                {
                    v.push_back(nums[(j+i+1)%nums.size()]);
                    break;
                }
            }
            if(j==nums.size())
            {
                v.push_back(-1);
            }
        }
        return v;
    }
};