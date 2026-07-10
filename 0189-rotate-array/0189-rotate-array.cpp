class Solution {
public:
    void rotate(vector<int>& nums, int k) 
    {
        k=k%nums.size();
        vector<int> temp;
        for(int i=nums.size()-k;i<nums.size();i++)
        {
            temp.push_back(nums[i]);
        }
        int last= nums.size()-1;
        for(int i =nums.size()-k-1;i>=0;i--)
        {
            nums[last]=nums[i];
            last--;
        }
        for(int i =0; i <k; i++)
        {
            nums[i]=temp[i];
        }
        
    }
};