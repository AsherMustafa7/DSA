class Solution {
public:
    int beautySum(string s) 
    {
        int count =0;
        for(int i =0; i <s.size();i++)
        {
            for(int j=i; j<s.size();j++)
            {
                count+=find_beauty(s,i,j);
            }
        }
        return count;
    }
    int find_beauty(string &s, int p, int q)
    {
        vector<int>v(26,0);
        int max=0; int min=INT_MAX;
        
        for(int i =p; i<=q;i++)
        {
            v[s[i]-'a']++;
                
        }
        for(int i =0; i<v.size();i++)
        {
            
            if(v[i]!=0)
            {
                if(max<v[i])
                {
                    max=v[i];
                }
                if(min>v[i])
                {
                    min=v[i];
                }
            }
            
        }
        
        return max-min;
    }
};