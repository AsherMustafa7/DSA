class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        int count=0;
        int element=nums[0];
        for(int i=0; i <nums.size();i++)
        {
            if(element==nums[i])
            {
                count++;
                element=nums[i];
            }
            else
            {
                count--;
                if(count==0)
                {
                    count++;
                    element=nums[i];
                }
            }
            
        }
        return element;
    }
};