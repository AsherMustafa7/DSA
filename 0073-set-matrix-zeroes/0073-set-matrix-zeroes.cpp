class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) 
    {
        unordered_map<int,int>m1;
        unordered_map<int,int>m2;
        for(int i =0; i<matrix.size();i++)
        {
            for(int j =0; j<matrix[0].size();j++)
            {
                if(matrix[i][j]==0)
                {
                    m1[i]=1;
                    m2[j]=1;
                }
                
            }
        }
        for(int i =0; i<matrix.size();i++)
        {
            for(int j =0; j<matrix[0].size();j++)
            {
                if(m1.find(i)!=m1.end() || m2.find(j)!=m2.end())
                {
                    matrix[i][j]=0;
                }
            }
        }
    }
};