class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) 
    {
        if(hand.size()%groupSize!=0)
        return false;
        map<int,int> mp;
        for(int x:hand)
        {
            mp[x]++;
        }
        while(!mp.empty())
        {
            int p= mp.begin()->first;
            mp.begin()->second--;
            if(mp.begin()->second==0)
            {
                mp.erase(p);
            }
            for(int i =0; i <groupSize-1;i++)
            {
                p++;
                if(mp.find(p)==mp.end())
                {
                    return false;
                }
                else
                {
                    ((mp.find(p))->second)--;
                    if( (mp.find(p))->second==0 )
                    {
                        mp.erase(p);
                    }
                }
                
            }
        }
        return true;
    }
};