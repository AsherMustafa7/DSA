class Solution {
public:
    int characterReplacement(string s, int k) 
    {
        vector<int> mp(26,0);
        int l=0; int r=0;
        int max_l=0;
        int maxf=0;
        int len=0;
        while(r<s.size())
        {
            len=r-l+1;
            mp[s[r]-'A']++;
            maxf = max(maxf, mp[s[r] - 'A']);
            if(len-maxf<=k)
            {
                max_l=max(max_l,len);
            }
            else
            {
                mp[s[l]-'A']--;
                l++;
                len=r-l+1;
                maxf = max(maxf, mp[s[r] - 'A']);
                
            }
            r++;
        }
        return max_l;
    }
   
};