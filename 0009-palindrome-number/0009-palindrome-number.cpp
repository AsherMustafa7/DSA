class Solution {
public:
    bool isPalindrome(int x) 
    {
        int copy=x;
        long long newi=0;
        while(copy>0)
        {
            int d = copy%10;
            newi= newi*10+d;
            copy=copy/10;
        }
        if(newi==(long long)x)
        return true;
        return false;
    }
};