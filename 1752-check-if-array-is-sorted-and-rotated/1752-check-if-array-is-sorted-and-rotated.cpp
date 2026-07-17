class Solution {
public:
    bool check(vector<int>& nums) 
    {
        int count=0;
        int i =0;
        int k=0;
        while(i<nums.size())
        {
            if((nums[i%nums.size()])>nums[(i+1)%nums.size()])
            {
                count++;
            }
            i++;
            
        }
        if(count==1 || count ==0)
        return true;
        else return false;
    }
};