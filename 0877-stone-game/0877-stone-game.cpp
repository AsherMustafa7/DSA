class Solution {
public:
    bool stoneGame(vector<int>& piles) 
    {
        int flag=false;
        check(piles,0,piles.size()-1,0,0,flag,1);
        return flag;
        
    }
    void check(vector<int>& piles,int l,int r, int alice,int bob,int &flag, int flip)
    {
        if(l>=r)
        {
            if(alice>bob)
            {
                flag=true;
            }
            return;
        }
        if(flag==false)
        {
            if(flip==1)
            {
                check(piles,l+1,r,alice+piles[l],bob,flag,0);
                check(piles,l,r-1,alice+piles[r],bob,flag,0);
            }
            else
            {
                check(piles,l+1,r,bob+piles[l],bob,flag,1);
                check(piles,l,r-1,bob+piles[r],bob,flag,1);
            }
        }
        else
        {
            return;
        }
    }
};