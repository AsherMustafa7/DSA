class Solution {
public:
    string minWindow(string s, string t) 
    {
        unordered_map<char,int>mpp;
        int startind=-1;
        int mins=INT_MAX;
        int m =t.size();
        for(int i =0; i <t.size();i++)
        {
            mpp[t[i]]++;
        }
        int l=0; int r=0;
        int count =0;
        while(r<s.size())
        {
            if(mpp[s[r]]>0)
            {
                count++;
            }
            mpp[s[r]]--;
            while(count ==m)
            {
                if(r-l+1<mins)
                {
                    startind=l;
                    mins=r-l+1;
                }
                mpp[s[l]]++;
                if(mpp[s[l]]>0)
                {
                    count--;
                }
                l++;
            }
            r++;
        }
        return startind==-1?"":s.substr(startind,mins);
    }
};