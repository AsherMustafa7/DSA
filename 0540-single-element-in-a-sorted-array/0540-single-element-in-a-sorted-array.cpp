class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) 
    {
        int l=0;
        int r=nums.size()-1;
        int m=-1;
        if(nums.size()==1)
        {
            return nums[0];
        }
        while(l<=r)
        {
            m=l+(r-l)/2;
            if(m%2==0)
            {
                if(nums[m]==nums[m+1])
                {
                    l=m+1;
                }
                else
                {
                    r=m-1;
                }
            }
            else
            {
                if(nums[m]==nums[m-1])
                {
                    l=m+1;
                }
                else
                {
                    r=m-1;
                }
            }
        }
        return nums[l];
    }
};