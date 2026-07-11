class Solution {
public:
    string longestPalindrome(string& s) 
    {
        
        string ans="";
        for(int l=0; l<s.size();l++)
        {
            for(int r=s.size()-1; r>=l;r--)
            {
                if(check_pal(s,l,r) && ((r-l+1)>ans.size()))
                {
                    
                    
                        ans=s.substr(l,r-l+1);
                        break;
                    
                    
                }
            }
        }
        return ans;
    }
    bool check_pal(string& s, int p, int q)
    {
        
        while(p<q)
        {
            if(s[p]!=s[q])
            {
                return false;
                 
            }
            p++;
            q--;
        }
        return true;
          
    }
};