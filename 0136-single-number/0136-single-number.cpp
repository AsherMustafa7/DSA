class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
        unordered_map<int,int>mp;
        for(int i =0; i < nums.size();i++)
        {
            mp[nums[i]]++;
        }
        for(auto it:mp)
        {
            cout<< it.first<< ":" << it.second<<endl;
            if(it.second==1)
            return it.first;
        }
        return -1;
    }
};
// 1 1 2 2 4