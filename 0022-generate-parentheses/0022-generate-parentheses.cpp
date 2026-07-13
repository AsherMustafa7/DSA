class Solution {
public:
    vector<string> generateParenthesis(int n) 
    {
        vector<string>str;
        findp(str,n, "",0,0);
        return str;
    }
    void findp(vector<string>&str,int n, string s,int close,int open)
    {
        if(s.size()==2*n )
        {
            if(open==close)
            str.push_back(s);
            return;
        }
        
        if(open<n)
        {
            findp(str,n,  s+"(",close,open+1);
           
        }
        if(close<open && s.size()!=0)
        {
            findp(str,n,  s+")",close+1,open);
            
        }
        
    }

};