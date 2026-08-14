class Solution {
public:
    int maximumLengthSubstring(string s) 
    {
        unordered_map<char,int>mp;
        int l=0; 
        int maxlength=0;
        for(int r=0;r<s.size();r++)
        {
            char ch=s[r];
            mp[ch]++;
            while(mp[ch]>2)
            {
                mp[s[l]]--;
                l++;
            }
            maxlength=max(maxlength,r-l+1);

        }
        return maxlength;
    }
};