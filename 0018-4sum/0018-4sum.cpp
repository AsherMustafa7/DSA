class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        sort(nums.begin(),nums.end());
        vector<vector<int>> vf;
        long long sum=0;
        for(int i =0; i <nums.size()-1;i++)
        {
            if(i > 0 && nums[i] == nums[i - 1])
            continue;
            for(int j=i+1; j<nums.size()-2;j++)
            {
                if(j > i + 1 && nums[j] == nums[j - 1])
                continue;
                int k=j+1;
                int l=nums.size()-1;
                while(k<l)
                {
                    sum =(1LL*nums[i])+nums[j]+nums[k]+nums[l];
                    if(1ll*(sum)==1ll*target)
                    {
                        vf.push_back({nums[i],nums[j],nums[k],nums[l]});
                        k++;
                        l--;
                        if(k<l)
                        {
                            while(nums[k]==nums[k-1])
                            {
                                k++;
                                if(k>=l)
                                break;
                            }
                            while(nums[l]==nums[l+1])
                            {
                                l--;
                                if(k>=l)
                                break;
                            }
                        }
                        else
                        {
                            break;
                        }
                        
                    }
                    else if(1ll*(sum)<1ll*target)
                    {
                        k++;
                        if(k<l)
                        {
                            while(nums[k]==nums[k-1])
                            {
                                    k++;
                                    if(k>=l)
                                    break;
                            }
                        }
                        else
                        {
                            break;
                        }
                        
                    }
                    else if(1ll*(sum)>1ll*target)
                    {
                        l--;
                        if(k<l)
                        {
                            while(nums[l]==nums[l+1])
                            {
                                l--;
                                if(k>=l)
                                break;
                            }
                        }
                        
                        else
                        {
                            break;
                        }
                        
                    }
                }
            }
        }
        
        return vf;
    }
};