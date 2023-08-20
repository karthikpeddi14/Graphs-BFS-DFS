class Solution {
public:
    void f(vector<vector<int>>& adj,vector<int>& visited, int index)
    {
        visited[index] = 1;
        for(auto it:adj[index])
        {
            if(visited[it]!=1)
            {
                f(adj,visited,it);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(n);

        for(int i=0 ; i<n ; i++)
        {
            for(int j=i+1 ; j<n ; j++)
            {
                if(isConnected[i][j]==1) 
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<int> visited(n,0);
        int ans = 0;
        for(int i=0 ; i<n ; i++)
        {
            if(visited[i]==0) 
            {
                f(adj,visited,i);
                ans++;
            }
        }
        return ans;
    }
};
