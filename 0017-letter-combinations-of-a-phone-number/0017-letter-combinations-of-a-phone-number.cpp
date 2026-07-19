class Solution {
public:
    vector<string> letterCombinations(string digits) 
    {
        unordered_map<char,string>v;
        v['1']="";
        v['2']="abc";
        v['3']="def";
        v['4']="ghi";
        v['5']="jkl";
        v['6']="mno";
        v['7']="pqrs";
        v['8']="tuv";
        v['9']="wxyz";
        vector<string>vf;
        finds(vf,v,"",v[digits[0]],0,digits);
        
        return vf;
    }
    void finds(vector<string>&vf,unordered_map<char,string>&v,string strm, string f,int index,string &digits)
    {
        if(strm.size()==digits.size())
        {
            vf.push_back(strm);
            return;
        }
        if(index==digits.size())
        {
            return;
        }
        for(int i =0; i <f.size();i++)
        {
            if(index!=digits.size())
            finds(vf,v,strm+f[i],v[digits[index+1]],index+1,digits);
            finds(vf,v,strm,v[digits[index]],index+1,digits);
        }
        return;
    }
};