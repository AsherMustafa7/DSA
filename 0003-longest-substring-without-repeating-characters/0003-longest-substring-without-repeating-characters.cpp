class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0;
        int r=0;
        int length=0;
        int maxlength=0;
        map<char, int> mp;
        if(s.size()==0)
        {
            return 0;
        }
        for(int r=0; r<s.size();r++)
        {
            if(mp.find(s[r])!=mp.end())
            {
                if(mp[s[r]]>=l)
                {
                    l=mp[s[r]]+1;
                }
            }
            mp[s[r]]=r;
            length= r-l+1;
            maxlength=max(length,maxlength);
        }
        return maxlength;
    }
};