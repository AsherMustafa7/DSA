class Solution {
public:
    void rotate(vector<int>& nums, int k) 
    {
        k=k%nums.size();
        int n = nums.size();
        vector<int> temp(nums.size(),0);
        for(int i =0; i <nums.size();i++)
        {
            temp[i]= nums[(i+(n-k))%n];
        }
        nums=temp;
    }
};