//using dfs
class Solution {
  public:
    void dfs(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& visited,vector<pair<int,int>>& per_dfs, int ai,int aj)
    {
        int n = grid.size();
        int m = grid[0].size();
        visited[i][j] = 1;
        per_dfs.push_back({i-ai,j-aj});
        
        if(i<n-1 && grid[i+1][j]==1 && visited[i+1][j]==0) dfs(grid,i+1,j,visited,per_dfs,ai,aj);
        if(j<m-1 && grid[i][j+1]==1 && visited[i][j+1]==0) dfs(grid,i,j+1,visited,per_dfs,ai,aj);
        if(i>0 && grid[i-1][j]==1 && visited[i-1][j]==0) dfs(grid,i-1,j,visited,per_dfs,ai,aj);
        if(j>0 && grid[i][j-1]==1 && visited[i][j-1]==0) dfs(grid,i,j-1,visited,per_dfs,ai,aj);
        
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        set<vector<pair<int,int>>> st;
        vector<pair<int,int>> per_dfs;
    
        for(int i=0 ; i<n ; i++)
        {
            for(int j=0; j<m ; j++)
            {
                if(grid[i][j] ==1 && visited[i][j]==0){
                    dfs(grid,i,j,visited,per_dfs,i,j);
                    st.insert(per_dfs);
                    per_dfs.clear();
                } 
            }
        }
        return st.size();
    }
};
