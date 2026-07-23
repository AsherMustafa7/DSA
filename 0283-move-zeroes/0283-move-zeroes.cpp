class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int l=0;
        for(int i =1; i <nums.size() && l<nums.size();)
        {
            if(nums[l]==0 && nums[i]!=0)
            {
                swap(nums[l],nums[i]);
                i++;
                l++;
            }
            else if(nums[l]==0 && nums[i]==0)
            {
                i++;
            }
            else if(nums[l]!=0 && nums[i]==0)
            {
                l++;
            }
            else if(nums[l]!=0 && nums[i]!=0)
            {
                l++;
                i++;
            }
        }
    }
};