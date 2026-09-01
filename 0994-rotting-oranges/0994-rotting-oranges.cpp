class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
        int n =grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        for(int i =0; i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    vis[i][j] = 1; 
                    q.push({i,j});
                }
            }
        }
        if(q.empty())
        {
                for(int i =0; i<n;i++)
                {
                    for(int j=0;j<m;j++)
                    {
                        if(grid[i][j]==1)
                        {
                            return -1;
                        }
                    }
                }
                return 0;
        }
        int time=0;
        while(!q.empty())
        {
            int size=q.size();
            for(int p =0; p <size;p++)
            {
                    int row=q.front().first;
                    int col=q.front().second;
                    q.pop();
                    
                    
                    int ar[]={0,0,-1,1};
                    int cr[]={-1,1,0,0};
                    for(int i =0;i<4;i++)
                    {
                        int nrow=row+ar[i];
                        int ncol=col+cr[i];
                        if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && vis[nrow][ncol]==0 && grid[nrow][ncol]==1)
                        {
                            vis[nrow][ncol]=1;
                            grid[nrow][ncol]=2;
                            q.push({nrow,ncol});
                        }
                    }
            }
            time++; 
        }
        for(int i =0; i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    return -1;
                }
            }
        }
        return time-1;
    }
};