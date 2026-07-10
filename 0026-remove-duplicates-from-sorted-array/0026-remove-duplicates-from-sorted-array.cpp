class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        
        int l=0; int r=1;
        int count=1;
        while(r<nums.size())
        {
            if(nums[l]==nums[r])
            {
                r++;
            }
            else
            {
                l++;
                nums[l]=nums[r];
                r++;
                count++;
            }
        }
        return count;
    }
};