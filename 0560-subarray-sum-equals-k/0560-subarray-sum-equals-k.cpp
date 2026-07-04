class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int prefixsum=0;
        int count=0;
        map<int,int> mp;
        
        for(int i =0; i <nums.size();i++)
        {
            mp[prefixsum]++;
            prefixsum+=nums[i];
            
            if(mp.find(prefixsum-k)!=mp.end())
            {
                count+=mp[prefixsum-k];
            }
            
        }
        return count;
    }
};