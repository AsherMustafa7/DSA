class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) 
    {
        int maxlen=0;
        int len=0;
        for(int i =0; i <nums.size();i++)
        {
            if(nums[i]==0)
            {
                len=0;
            }
            if(nums[i]==1)
            {
                len++;
            }
            if(maxlen<len)
            {
                maxlen=max(maxlen,len);
            }
        }
        return maxlen;
    }
};