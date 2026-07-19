class Solution {
public:
    vector<string> letterCombinations(string digits) 
    {
        unordered_map<char,string>mp;
        mp['1']="";
        mp['2']="abc";
        mp['3']="def";
        mp['4']="ghi";
        mp['5']="jkl";
        mp['6']="mno";
        mp['7']="pqrs";
        mp['8']="tuv";
        mp['9']="wxyz";
        vector<string>vf;
        finds(vf,mp,"",0,digits);
        
        return vf;
    }
    void finds(vector<string>& vf,unordered_map<char,string> &mp,string str,int index,string &digits)
    {
        if(str.size()==digits.size())
        {
            vf.push_back(str);
            return;
        }
        if(index==digits.size())
        {
            return;
        }
        for(int i=0; i <mp[digits[index]].size();i++)
        {
            str.push_back(mp[digits[index]][i]);
            finds(vf,mp,str,index+1,digits);
            str.pop_back();
        }
    }
};