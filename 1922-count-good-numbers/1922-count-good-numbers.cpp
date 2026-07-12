class Solution {
public:
    int countGoodNumbers(long long n) 
    {
        int const MOD = 1e9+7;
        if(n%2==0)
        return (pp(5,n/2)*pp(4,n/2))%MOD;
        return (pp(5,(n/2)+1)*pp(4,n/2))%MOD;
    }
    long long pp(long long x, long long n)
    {
        long long N=n;
        long long ans=1;
        int const MOD = 1e9+7;
        while(N>0)
        {
            if(N%2==0)
            {
                x=(x*x)%MOD;
                N=N/2;
            }
            else
            {
                ans=(ans*x)%MOD;
                N=N-1;
            }
        }
        return ans;
    }
    // 5 4 5 4
    // 5 4 5 4 5
    // 0 1 2 3 4
};