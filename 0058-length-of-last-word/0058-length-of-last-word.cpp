class Solution 
{
public:
    int lengthOfLastWord(string s) 
    {

        int LI= s.size()-1;
        char ch= s[LI];
        int count =0;
        while(ch==' ')
        {
            LI--;
            ch=s[LI];
        }
        while(ch!=' ' && LI>=0)
        {
            count++;
            LI--;
            if(LI>=0)
            ch=s[LI];
            else
            break;
        }
        return count;
    }
};