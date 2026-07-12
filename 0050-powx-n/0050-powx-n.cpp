class Solution {
public:
    double myPow(double x, int n) 
    { 
        if(n==0)
        return 1;
        else if(n<0)
        x=1/x;
        return pp(x,n);
    }
    double pp(double num,int n)
    {
        if(n==0)
        return 1;
        double half= pp(num,n/2);
        if(n%2==0)
        {
            return half*half;
        }
        return half*half*num;
    }
   
};