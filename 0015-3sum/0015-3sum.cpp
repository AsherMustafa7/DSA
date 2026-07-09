class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        vector<vector<int>>v;
        sort(nums.begin(),nums.end());
        int i=0; int j=1;
        int k=nums.size()-1;
        while(i<nums.size()-2)
        {
            while(j<k)
            {
                if(nums[i]+nums[j]+nums[k]==0)
                {
                    v.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    if(j==k)
                    {
                        break;
                    }
                    k--;
                    while(j < k && nums[j] == nums[j-1])
                    {
                        j++;
                    }
                    while(j < k && nums[k] == nums[k+1])
                    {
                        k--;
                    }

                }
                else if(nums[i]+nums[j]+nums[k]<0)
                {
                    j++;
                }
                else
                {
                    k--;
                }
            }
            i++;
            while(i < nums.size() && nums[i] == nums[i-1])
            {
                i++;
            }
            j=i+1;
            k=nums.size()-1;
        }
        return v;
    }
};