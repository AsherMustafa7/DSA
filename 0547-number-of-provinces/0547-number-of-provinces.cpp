class Solution {
private:
    void dfs(int i , vector<int>&vis, vector<vector<int>>&adj)
    {
        vis[i]=1;
        for(auto it:adj[i])
        {
            if(!vis[it])
            {
                dfs(it,vis,adj);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<vector<int>> adj(isConnected.size());
        int n=isConnected.size();
        int m=isConnected[0].size();
        vector<int>vis(n,0);
        for(int i =0; i <n;i++)
        {
            for(int j=0; j<m;j++)
            {
                if(isConnected[i][j]==1)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int count =0;
        for(int i =0; i<n;i++)
        {
            if(!vis[i])
            {
                dfs(i,vis,adj);
                count++;
            }
        }
    return count;
    }
};