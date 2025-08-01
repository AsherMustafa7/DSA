class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=0;
        int flag=false;
        for(int i =0; i <nums.size();i++)
        {

            for(int j =0; j<nums.size();j++)
            {
                if(nums[j]==n)
                {
                    flag=true;
                }
            }
            if(flag==false)
            {
                return n;
            }
            else{
                flag=false;
            }
            n++;
            
        }
        return n;
    }
};