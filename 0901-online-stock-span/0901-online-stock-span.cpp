class StockSpanner {
public:
    vector<int> v;
    int val=-1;
    StockSpanner() {
        
    }
    int next(int price) 
    {
        
        
        v.push_back(price);
        int c=0;
        val++;
        int f=1;
        for(int i =val; i>=0;i--)
        {   if(f==0)
            {
                break;
            }
            if(price>=v[i])
            {
               
                c++;
            }
            else
            {
                f=0;
            }
        }
        
        return c;
    }

};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */