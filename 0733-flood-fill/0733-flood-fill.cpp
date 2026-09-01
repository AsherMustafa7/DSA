class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
    {
        vector<vector<int>>filled=image;
        int intcolor=image[sr][sc];
        if(intcolor==color)
        {
            return image;
        }
        dfs(filled,image,sr,sc,color,intcolor);
        return filled;
    }
    void dfs(vector<vector<int>>&filled,vector<vector<int>>&image,int sr,int sc,int &color,int &intcolor)
    {
        filled[sr][sc]=color;
        int n =image.size();
        int m=image[0].size();
        int ar[]={0,0,-1,1};
        int cr[]={-1,1,0,0};
        for(int i =0;i<4;i++)
        {
            int nrow=sr+ar[i];
            int ncol=sc+cr[i];
            if(nrow>=0 &&ncol>=0 && nrow<n && ncol<m && image[nrow][ncol]==intcolor && filled[nrow][ncol]==intcolor)
            {
                dfs(filled,image,nrow,ncol,color,intcolor);
            }
        }
    }
};