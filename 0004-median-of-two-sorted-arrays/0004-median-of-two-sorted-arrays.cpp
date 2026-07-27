class Solution 
{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<int>v;
        int r= 0;
        int l=0;
        while(l<nums1.size() && r<nums2.size())
        {
            if(nums1[l]<=nums2[r])
            {
                v.push_back(nums1[l]);
                l++;
            }
            else
            {
                v.push_back(nums2[r]);
                r++;
            }
        }
        if(l<nums1.size())
        {
            while(l<nums1.size())
            {
                v.push_back(nums1[l]);
                l++;
            }
        }
        if(r<nums2.size())
        {
            while(r<nums2.size())
            {
                v.push_back(nums2[r]);
                r++;
            }
        }
        for(auto i:v)
        {
            cout<<i << " ";
        }
        if(v.size()%2!=0)
        {
            return (1.0)*(v[v.size()/2]);
        }
        
        return ((double)v[v.size()/2] + (double)v[v.size()/2 - 1]) / 2.0;;
    }
};