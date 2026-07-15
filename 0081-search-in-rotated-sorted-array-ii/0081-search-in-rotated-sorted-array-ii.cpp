class Solution {
public:
    bool search(vector<int>& nums, int target) 
    {
        int l =0; 
        int r =nums.size()-1;
        int m= 0;
       
        while(l<=r)
        {
            m= (l+(r-l)/2);
            if(nums[m]==target)
            {
                return true;
            }
            
            if(nums[l]<=nums[m])
            {
                if(nums[l]<=target && target <nums[m])
                {
                    r=r-1;
                }
                else
                {
                    l=l+1;
                }
            }
            else
            {
                if(nums[r]>=nums[m])
                {
                    if(nums[m]<target && target <=nums[r])
                    {
                        l=l+1;
                    }
                    else
                    {
                        r=r-1;
                    }
                }
            }
        }
        return false;
    }
};