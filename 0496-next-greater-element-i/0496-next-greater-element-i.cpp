class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<int>v;
        stack<int>st;
        if(nums2.size()==1)
        return {-1};
        unordered_map<int,int>mp;
        st.push(nums2[nums2.size()-1]);
        for(int i =nums2.size()-2;i>=0;i--)
        {
            while(!st.empty()&& nums2[i]>st.top())
            {
                st.pop();
            }
            if(!st.empty())
            {
                mp[nums2[i]]=st.top();
            }
            st.push(nums2[i]);
        }
        for(int i=0; i<nums1.size();i++)
        {
            if(mp[nums1[i]]==0)
            v.push_back(-1);
            else
            v.push_back(mp[nums1[i]]);
        }
        return v;
    }
};