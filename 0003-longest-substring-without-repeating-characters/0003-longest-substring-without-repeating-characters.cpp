class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0;
        int maxlength=0;
        int length=0;
        vector<int> mp(256,-1);
        for(int r=0; r<s.size();r++)
        {
            if(mp[s[r]]==-1)
            {
                length=r-l+1;
                maxlength=max(length,maxlength);
                mp[s[r]]=r;

            }
            else
            {
                if(mp[s[r]]>=l)
                {
                    l=mp[s[r]]+1;
                }
                

                length=r-l+1;
                maxlength=max(length,maxlength);
                mp[s[r]]=r;
            }
        }
        return maxlength;
    }
};