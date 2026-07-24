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
        while(it!=mp.end())
        {
            
            if(it->second==1)
            return it->first;
            it++;
        }
        return -1;
    }
};
// 1 1 2 2 4