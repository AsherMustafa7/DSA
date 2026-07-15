class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0;
        int r=nums.size()-1;
        int m=-1;
        while(l<=r)
        {
            m=l+(r-l)/2;
            if(target==nums[m])
            {
                return m;
            }
            if(target>nums[m])
            {
                l=m+1;
            }
            else
            {
                r=m-1;
            }
        }
        return -1;
    }
};