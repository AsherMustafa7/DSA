class Solution {
public:
    int strStr(string haystack, string needle) 
    {
        int h= haystack.size();
        int n= needle.size();
        if(n>h)
        {
            return -1;
        }
        if(haystack==needle)
        {
            return 0;
        }
        int i =0;
        while(needle!=haystack.substr(i,n) && i<=h-n)
        {
            
            i++;
        }
        if(i<=h-n)
        return i;
        return -1;

    }
};