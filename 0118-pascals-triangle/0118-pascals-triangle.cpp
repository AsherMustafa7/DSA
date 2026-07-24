class Solution {
public:
    vector<vector<int>> generate(int numRows) 
    {
        vector<vector<int>> vf;
        vector<int> v;
        int i=0;
        for(int i =0; i <numRows;i++)
        {
            for(int j=0;j<=i;j++)
            {
                if(j==0 || j==i)
                {
                    v.push_back(1);
                }
                else if(i!=0 )
                {
                    v.push_back(vf[i-1][j-1]+vf[i-1][j]);
                }
            }
            vf.push_back(v);
            v.clear();
        }
        return vf;
    }
};