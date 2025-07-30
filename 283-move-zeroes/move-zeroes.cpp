class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int l=nums.size();
        vector<int> arr(l);
        int r=nums.size()-1;
        int m=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                arr[r]=0;
                r--;
            }
            else{
                arr[m]=nums[i];
                m++;
            }
        }
        for(int i =0;i<arr.size();i++)
        {
            nums[i]=arr[i];
        }
    }
};