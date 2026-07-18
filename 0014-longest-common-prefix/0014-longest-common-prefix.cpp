class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
       
       string comstr=strs[0];
       int k=0;
       for(int i =1; i <strs.size();i++)
       {
            
            int j=0;
            for(j=0; j<strs[i].size();j++)
            {
                
                if(j<comstr.size()&& j<strs[i].size()&& (comstr[j]!=strs[i][j]))
                {
                        k=j;
                        break;
                }
                
            }
            comstr=comstr.substr(0,j);
       }
       return comstr;
    }
};