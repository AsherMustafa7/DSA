class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        if(nums.size()<2)
        return 0;
        int max1=INT_MIN;
        int max2=INT_MIN;
        for(int i =0; i <nums.size();i++)
        {
            if(max1<=nums[i])
            {
                max2=max1;
                max1=nums[i];
            }
            else if(nums[i]>max2)
            {
                max2=nums[i];
            }
        }
        if(max1!=INT_MIN && max2!=INT_MIN)
        return ((1LL)*(max1-1)*(max2-1));
        return 0;
    }
};