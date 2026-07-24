class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {
        int l=m-1;
        int r=n-1;
        int p=nums1.size()-1;
        while(l >= 0 && r >= 0)
        {
            
                if(nums1[l]>=nums2[r])
                {
                    nums1[p]=nums1[l];
                    l--;
                }
                else if(nums1[l]<nums2[r])
                {
                    nums1[p]=nums2[r];
                    r--;
                }
            
            p--;  
        }
        while(r >= 0)
        {
            nums1[p] = nums2[r];
            r--;
            p--;
        }
    }
};