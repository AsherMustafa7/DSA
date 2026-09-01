class Solution {
private:
    void dfs(int row, int col, vector<vector<int>> &vis,vector<vector<char>> &grid)
    {
        vis[row][col]=1;
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;
        q.push({row,col});
        int ar[]={0,0,-1,+1};
        int cr[]={-1,+1,0,0};
            for(int i =0;i<4;i++)
            {
                int nrow=row+ar[i];
                int ncol=col+cr[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]=='1'&& vis[nrow][ncol]==0)
                {
                    dfs(nrow,ncol,vis,grid);
                }
            }
        }
public:
    int numIslands(vector<vector<char>>& grid) 
    {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int cnt=0;;
        for(int i =0; i<n;i++)
        {
            for(int j=0; j<m;j++)
            {
                if(grid[i][j]=='1' && vis[i][j]==0)
                {
                    dfs(i,j,vis,grid);
                    cnt++;
                }
                
            }
        }
        return cnt;
    }
};