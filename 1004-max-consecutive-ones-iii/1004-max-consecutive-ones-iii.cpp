class Solution {
public:
    int longestOnes(vector<int>& nums, int k) 
    {
        int zeros=0;
        int l=0; int r=0;
        int max_l=0;
        int len=0;
        while(r<nums.size())
        {
            if(zeros<k)
            {
                if(nums[r]==0)
                {
                    zeros++;
                }
                len=r-l+1;
                max_l=max(len,max_l);
                r++;
            }
            else
            {
                if(nums[r]==0)
                {
                    if(nums[l]==0)
                    {
                        l++;
                        len=r-l+1;
                        max_l=max(len,max_l);
                        r++;
                    }
                    else
                    {
                        l++;
                    }
                }
                else
                {
                    len=r-l+1;
                    max_l=max(len,max_l);
                    r++;
                }
                
            }
        }
        return max_l;
    }
};