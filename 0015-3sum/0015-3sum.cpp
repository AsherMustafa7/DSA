class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>>s;
        unordered_map<int,int>mp;
        for(int i =0; i <nums.size();i++)
        {
            mp[nums[i]]=i;
        }
        if(mp.size()==1 && mp.find(0)!=mp.end())
        {
            return vector<vector<int>>{{0,0,0}};
        }
        
        for(int i=0; i <nums.size();i++)
        {
            
            for(int j=i+1;j<nums.size();j++)
            {
                if(mp.find(-nums[i]-nums[j])!=mp.end())
                {
                    if(i!=mp[-nums[i]-nums[j]] && j!=mp[-nums[i]-nums[j]])
                    {
                        vector<int> temp={nums[i],nums[j],-nums[i]-nums[j]};
                        sort(temp.begin(), temp.end());
                        s.insert(temp);
                    }
                }
            }
        }
        vector<vector<int>> ans(s.begin(),s.end());
        return ans;
    }
};