class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
      int b=0;
      int d=0;
      int p=0;
      for(int i =0; i < prices.size();i++)
      {
        d= prices[i]-prices[b];
        if(d>p)
        {
            p=d;
        }
        if(prices[b]>prices[i])
        {
            b=i;
        }
      }
      return p;
    }
};