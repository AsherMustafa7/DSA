class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        // Always binary search the smaller array
        if(nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);

        int n1 = nums1.size();
        int n2 = nums2.size();

        int low = 0;
        int high = n1;

        while(low <= high)
        {
            // Partition in nums1
            int cut1 = (low + high) / 2;

            // Partition in nums2
            int cut2 = (n1 + n2 + 1) / 2 - cut1;

            // Elements just left and right of the partitions

            int L1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
            int R1 = (cut1 == n1) ? INT_MAX : nums1[cut1];

            int L2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];
            int R2 = (cut2 == n2) ? INT_MAX : nums2[cut2];

            // Correct partition found
            if(L1 <= R2 && L2 <= R1)
            {
                // Even total length
                if((n1 + n2) % 2 == 0)
                {
                    return (max(L1, L2) + min(R1, R2)) / 2.0;
                }

                // Odd total length
                return max(L1, L2);
            }

            // Too many elements taken from nums1
            else if(L1 > R2)
            {
                high = cut1 - 1;
            }

            // Too few elements taken from nums1
            else
            {
                low = cut1 + 1;
            }
        }

        return 0;
    }
};