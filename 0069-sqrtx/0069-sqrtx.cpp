class Solution {
public:
    int mySqrt(int x) {
        int l =0;
        int r=x;
        if(x==1)
        {
            return 1;
        }
        if(x==0)
        {
            return 0;
        }
        int m=-1;
        int ans=-1;
        while(l<=r)
        {
            
            m=l+(r-l)/2;
            long long sq = 1LL * m * m;
            if(sq==x)
            {
                return m;
            }
            if(sq>x)
            {
                
                r=m-1;
            }
            else
            {
                ans=m;
                l=m+1;
            }
        }
        return ans;
    }
};