class Solution {
public:
    int findMin(vector<int>& nums) 
    {
        int l =0; int r=nums.size()-1;
        int m=-1;
        while(l<r)
        {
            m=l+(r-l)/2;
            if(nums[m]>nums[r])
            {
                l=1+m;
            }
            else
            {
                r=m;
            }
        }
        return nums[r];
    }
};