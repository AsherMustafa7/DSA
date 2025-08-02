class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) 
    {
        vector<int> p;
        for(int i=0;i<nums.size();i++)
        {
            int index=abs(nums[i])-1;
            if(nums[index]>0)
            {
                
                nums[index]=nums[index]*(-1);
            }
        }
        for(int i =0;i<nums.size();i++)
        {
            if(nums[i]>0){
                p.push_back(i+1);
            }
        }
        return p;
    }
};