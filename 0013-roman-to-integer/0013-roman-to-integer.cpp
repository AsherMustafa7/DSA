class Solution {
public:
    int romanToInt(string s)
    {
        map<char, int> mp;
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;

        vector<string> str;

        int l = 0;
        int r = 0;

        while (r < s.size() - 1)
        {
            if (mp[s[r + 1]] >= mp[s[r]])
            {
                r++;
            }
            else
            {
                str.push_back(s.substr(l, r - l + 1));
                l = r + 1;
                r++;
            }
        }

        // Handle the last remaining part
        if (l <= r)
        {
            str.push_back(s.substr(l, r - l + 1));
        }

        int sum = 0;

        for (int i = 0; i < str.size(); i++)
        {
            string strs = str[i];

            if (strs.size() == 1)
            {
                sum += mp[strs[0]];
            }
            else if (strs.size() == 2)
            {
                if (mp[strs[0]] < mp[strs[1]])
                    sum += mp[strs[1]] - mp[strs[0]];
                else
                    sum += mp[strs[0]] + mp[strs[1]];
            }
            else
            {
                for (char c : strs)
                    sum += mp[c];
            }
        }

        return sum;
    }
};