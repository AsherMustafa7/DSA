class Solution {
public:
    vector<string> validStrings(int n) {
        vector<string>str;
        if(n==1)
        {
            str.push_back("0");
            str.push_back("1");
            return str;
        }
        string s(n,'0');
        find_com(s,0,str);
        return str;
    }
    void find_com(string s, int i, vector<string>&str)
    {
        if(i==s.size())
        {
            if(s.find('1')!=-1)
            {
                str.push_back(s);
            }
            return;
        }
        if (i == 0 || s[i - 1] == '1')
        {
            s[i] = '0';
            find_com(s, i + 1, str);
        }
        s[i] = '1';
        find_com(s, i + 1, str);
    }
};