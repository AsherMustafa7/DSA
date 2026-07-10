class Solution {
public:
    bool check(vector<int>& nums) 
    {
        int count=0;
        int i =1;
        int k=0;
        while(k<nums.size())
        {
            if((nums[i%nums.size()])<nums[(i-1)%nums.size()])
            {
                count++;
            }
            i++;
            k++;
        }
        if(count==1 || count ==0)
        return true;
        else return false;
    }
};