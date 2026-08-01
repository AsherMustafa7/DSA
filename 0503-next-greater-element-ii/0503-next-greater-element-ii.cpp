class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) 
    {
        int p=0;
        vector<int>v(nums.size(),-1);
        stack<int>st;
        for(int i=nums.size()-2;i>=0;i--)
        {
            st.push(nums[i]);
        }
        for(int i =nums.size()-1; i >=0;i--)
        {
            while(!st.empty() && nums[i]>=st.top())
            {
                st.pop();
            }
            if(!st.empty())
            {
                v[i]=st.top();
            }
                st.push(nums[i]);
        }
        return v;
    }
};