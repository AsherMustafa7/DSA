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
        bfs(filled,image,sr,sc,color,intcolor);
        return filled;
    }
    void bfs(vector<vector<int>>&filled,vector<vector<int>>&image,int sr,int sc,int &color,int &intcolor)
    {
        filled[sr][sc]=color;
        int n =image.size();
        int m=image[0].size();
        int ar[]={0,0,-1,1};
        int cr[]={-1,1,0,0};
        queue<pair<int, int>>q;
        q.push({sr,sc});
        while(!q.empty())
        {
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(int i =0;i<4;i++)
            {
                int nrow=row+ar[i];
                int ncol=col+cr[i];
                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && image[nrow][ncol]==intcolor && filled[nrow][ncol]==intcolor)
                {
                    filled[nrow][ncol]=color;
                    q.push({nrow,ncol});
                }
            }
        }
        
    }
};