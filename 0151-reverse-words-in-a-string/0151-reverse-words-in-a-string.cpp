class Solution {
public:
    string reverseWords(string s) 
    {
        s.erase(0,s.find_first_not_of(' '));
        string total="";
        string str="";
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!=' ')
            {
                str=str+s[i];
            }
            else
            {
                if(str.size()!=0)
                total=str+" "+total;
                str="";
            }
        }
        total=str+" "+total;
        total.erase(0,total.find_first_not_of(' '));
        return total.substr(0,total.size()-1);
    }
    
};