class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        int p=nums[0];
        int q=nums[nums.size()-1];
        vector<int>v;
        int k=0;
        for(int i =p; i <=q && k<nums.size();i++)
        {
            if(i==nums[k])
            {
                k++;
            }
            else
            {
                v.push_back(i);
            }
        }
        return v;
    }
};
// 1 5 
// 