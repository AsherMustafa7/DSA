class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) 
    {
        int i=0; int j=1;
        vector<int> arr= nums;
        for(int k=0; k<arr.size();k++)
        {
            if(arr[k]>0)
            {
                nums[i]=arr[k];
                i+=2;
            }
            else
            {
                nums[j]=arr[k];
                j=j+2;
            }
        }
        return nums;
    }
};