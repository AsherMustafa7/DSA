class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) 
    {
        if(customers.size()==0)
        return 0;
        int sum=0;
        for(int i =0; i<customers.size();i++)
        {
            if(grumpy[i]==0)
            sum+=customers[i];
        }
        int sumg=0;
        int sumgm=0;
        int l=0; 
        int r=minutes-1;
        for (int i =0; i <minutes;i++)
        {
            if(grumpy[i]==1)
            {
                sumg+=customers[i];
            }
        }
        sumgm=sumg;
        l=0;
        r=minutes;
        while(r<customers.size())
        {
            if(grumpy[r]==1)
            {
                sumg+=customers[r];
            }
            if(grumpy[l]==1)
            {
                sumg-=customers[l];
            }
            sumgm=max(sumg,sumgm);
            r++;
            l++;
        }
        return sum+sumgm;
    }
};