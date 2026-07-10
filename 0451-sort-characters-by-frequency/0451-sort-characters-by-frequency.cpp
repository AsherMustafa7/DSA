class Solution {
public:
    string frequencySort(string s) 
    {
        map<char,int>mp;
        for(int i=0; i <s.size();i++)
        {
            mp[s[i]]++;
        }
        vector<vector<char>> v(s.size()+1);
        for(auto &it:mp)
        {
            v[it.second].push_back(it.first);
        }
        string ans="";
        for(int i = v.size()-1;i>=0;i--)
        {
            for(int j=0; j<v[i].size();j++)
            {
                ans+=string(i,v[i][j]);
            }
        }
        return ans;
    }
};