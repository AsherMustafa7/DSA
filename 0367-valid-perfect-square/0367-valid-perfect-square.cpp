class Solution {
public:
    bool isPerfectSquare(int num) {
        int l=1;
        int r =num;
        while(l<=r)
        {
            int m =l+(r-l)/2;
            if(1LL*m*m==1LL*num)
            {
                return true;
            }
            if(1LL*m*m>1LL*num)
            {
                r=m-1;
            }
            else
            {
                l=m+1;
            }
        }
        return false;
    }
};