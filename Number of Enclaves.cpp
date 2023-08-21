class Solution {
public:
    void dfs(int a, int b , vector<vector<int>>& visited, vector<vector<int>>& board)
    {
        visited[a][b] = 1;
        int n = board.size();
        int m = board[0].size();
        if(a>0 && board[a-1][b]==1 && visited[a-1][b]==0) dfs(a-1,b,visited,board);
        if(a<n-1 && board[a+1][b]==1 && visited[a+1][b]==0) dfs(a+1,b,visited,board);
        if(b>0 && board[a][b-1]==1 && visited[a][b-1]==0) dfs(a,b-1,visited,board);
        if(b<m-1 && board[a][b+1]==1 && visited[a][b+1]==0) dfs(a,b+1,visited,board);
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        for(int j=0 ; j<m ; j++)
        {
            if(visited[0][j]!=1 && grid[0][j]==1)
            {
                dfs(0,j,visited,grid);
            }
            if(visited[n-1][j]!=1 && grid[n-1][j]==1)
            {
                dfs(n-1,j,visited,grid);
            }
        }

        for(int i=0 ; i<n ; i++)
        {
            if(visited[i][0]!=1 && grid[i][0]==1)
            {
                dfs(i,0,visited,grid);
            }
            if(visited[i][m-1]!=1 && grid[i][m-1]==1)
            {
                dfs(i,m-1,visited,grid);
            }
        }

        int count = 0;
        for(int i=0 ; i<n ; i++)
        {
            for(int j=0 ; j<m ; j++)
            {
                if(visited[i][j]==0 && grid[i][j]==1) count++;
            }
        }
        return count;
    }
};
