class Solution {
public:
    long long countCommas(long long n) 
    {
        if(n < 1000)
            return 0;

        // 1,000 - 999,999
        // 1 comma
        if(n < 1000000LL)
            return n - 1000LL + 1;

        // 1,000,000 - 999,999,999
        // 2 commas
        if(n < 1000000000LL)
            return 999000LL
                 + 2LL * (n - 1000000LL + 1);

        // 1,000,000,000 - 999,999,999,999
        // 3 commas
        if(n < 1000000000000LL)
            return 1998999000LL
                 + 3LL * (n - 1000000000LL + 1);

        // 1,000,000,000,000 - 999,999,999,999,999
        // 4 commas
        if(n < 1000000000000000LL)
            return 2998998999000LL
                 + 4LL * (n - 1000000000000LL + 1);

        // n = 1,000,000,000,000,000
        // This number has 5 commas
        return 3998998998999005LL;
    }
};