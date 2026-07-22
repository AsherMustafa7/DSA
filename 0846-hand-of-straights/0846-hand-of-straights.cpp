class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) 
    {
        sort(hand.begin(),hand.end());
        int n=groupSize;
        int x=hand[0];
        int p=x;
        hand[0]=-1;
        p++;
        for(int i=0; i <hand.size();)
        {
            for(int j=0; j<=hand.size() && ((p-x)<groupSize);j++)
            {
                if(j==hand.size() && ((p-x)!=groupSize))
                {
                    return false;
                }
                if(i!=j && hand[j]==p && hand[j]!=-1)
                {
                    p++;
                    hand[j]=-1;
                }
            }
            if(hand[i]==-1)
            {
                i++;
            }
            else
            {
                p=hand[i];
                x=p;
                hand[i]=-1;
                p++;
            }
        }
        return true;
    }
};