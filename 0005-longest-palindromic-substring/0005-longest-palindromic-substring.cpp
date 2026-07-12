class Solution {
public:
    string longestPalindrome(string s) 
    {
       
        string str="";
        string odd="";
        string even="";
        if(s.size()==1)
        return s;
        for(int i =0; i<s.size()-1;i++)
        {
                even=func(s,i,i+1);
                if(str.size()<even.size())
                {
                    str=even;
                }
                odd=func(s,i,i);
                if(str.size()<odd.size())
                {
                    str=odd;
                }
            
        }
        return str;
     }
    string func(string &s, int l,int r)
    {
        while(l>=0&& r<s.size() && s[l]==s[r] )
        {
            l--;
            r++;
        }
        return s.substr(l+1,r-l-1);;
    }
};