class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<int>v;
        for(int i =0; i <nums1.size();i++)
        {
            int val= nums1[i];
            int ind=-1;
            find_greater(val,nums2,ind);
            v.push_back(ind);
        }
        return v;
    }
    void find_greater(int val, vector<int>&nums2,int &ind)
    {
        stack<int>st;
        if(val==nums2[nums2.size()-1])
        {
            return;
        }
        st.push(nums2[nums2.size()-1]);
        int i =nums2.size()-2;
        while(!st.empty() && i>=0)
        {
            if(nums2[i]<st.top())
            {
                if(val==nums2[i])
                {
                    ind=st.top();
                    return;
                }
                else
                {
                    st.push(nums2[i]);
                }
            }
            else
            {
                st.pop();
                if(val!=nums2[i])
                st.push(nums2[i]);
                else
                {
                    continue;
                }
            }
            i--;
        }
    }
};