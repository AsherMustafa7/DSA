class Solution {
public:
    bool checkDivisibility(int n) 
    {
        int sum=0;
        int p=1;
        int copy=n;
        while(copy>0)
        {
            sum=sum+(copy%10);
            p=p*(copy%10);
            copy=copy/10;
        }
        
        return (n%(sum+p))==0;
    }
};