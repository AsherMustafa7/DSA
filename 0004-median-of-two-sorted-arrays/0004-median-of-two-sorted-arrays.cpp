class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        int count=0;
        int l=0; int r=0;
        int n1=nums1.size();
        int n2=nums2.size();
        int prev = 0;
        int curr = 0;

        for(int count=0; count<=(n1+n2)/2;count++)
        {
            prev = curr;
            if(l<n1 && (r >= n2 || nums1[l] <= nums2[r]) )
            {
                curr=nums1[l];
                l++;
            }
            else
            {
                curr=nums2[r];
                r++;
            }
        }
        if((n1+n2) % 2 == 1)
        {
            return curr;
        }

        return (prev + curr) / 2.0;
    }
};