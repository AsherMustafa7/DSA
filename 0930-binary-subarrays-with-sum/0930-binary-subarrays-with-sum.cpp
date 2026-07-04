class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) 
    {
        int prefixsum=0;
        map<int, int> mp;
        mp[0]=1;
        int count=0;
        for(int i =0; i <nums.size();i++)
        {
            prefixsum+=nums[i];
            int remove= prefixsum-goal;
            count+=mp[remove];
            mp[prefixsum]++;
        }
        return count;
    }
};