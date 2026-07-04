class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        for(int i =0; i <nums.size();i++)
        {
            if(nums[i]%2==0)
            {
                nums[i]=0;
            }
            else
            {
                nums[i]=1;
            }
        }
        int prefixsum=0;
        int count=0;
        unordered_map<int,int> mp;
        mp[0]=1;
        for(int i =0; i < nums.size();i++)
        {
            prefixsum+=nums[i];
            int remove=prefixsum-k;
            if(mp.find(remove)!=mp.end())
            {
                count+=mp[remove];
            }
            mp[prefixsum]++;
        }
        return count;
    }
};