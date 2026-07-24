class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
        unordered_map<int,int>mp;
        for(int i =0; i < nums.size();i++)
        {
            mp[nums[i]]++;
        }
        auto it=mp.begin();
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            if(it->second==1)
            return it->first;
        }
        return -1;
    }
};
// 1 1 2 2 4