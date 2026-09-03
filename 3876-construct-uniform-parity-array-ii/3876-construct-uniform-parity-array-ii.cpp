class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int cnt=0;
        int even=0;
        int odd=0;
        int n =nums1.size();
        if(n==1)
        {
            return true;
        }
        for(int i =0; i <n;i++)
        {
            if(nums1[i]%2==0)
            {
                cnt++;
                even++;
            }
            else
            {
                odd++;
            }
        }
        if(cnt==n)
        {
            return true;
        }
        cnt=0;
        int flag=0;
       
        for(int i =0; i <n;i++)
        {
            if(nums1[i]%2!=0)
            {
                cnt++;
            }
        }
        if(cnt==n)
        {
            return true;
        }
        sort(nums1.begin(),nums1.end());
        if(nums1[0]%2!=0)
        {
            return true;
        }
        return false;
    }
};

// aptitide , group discussion , interview rounds(depends on volume)