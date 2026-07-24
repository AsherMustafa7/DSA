class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) 
    {
        int maxlen=0;
        int len=0;
        int l=0;
        int r=0;
        while(l<nums.size() && r<nums.size())
        {
            if(nums[l]==0)
            {
                l++;
            }
            if(nums[r]==1)
            {
                len=r-l+1;
                maxlen=max(len,maxlen);
            }
            else
            {
                l=r+1;
            }
            r++;
        }
        return maxlen;
    }
};