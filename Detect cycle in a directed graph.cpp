class Solution {
  public:
    bool dfs(vector<int> edges[], vector<int>& visited, vector<int>& path_visited, int index)
    {
    	visited[index] = 1;
    	path_visited[index] = 1;
    	for(auto it:edges[index])
    	{
    		if(visited[it]==0)
    		{
    			if(dfs(edges,visited,path_visited,it)==true)
    			return true;
    		}
    		else if(path_visited[it]==1) return true;
    	}
    	path_visited[index] = 0;
    	return false;
    }
    
    bool isCyclic(int v, vector<int> adj[]) {
        vector<int> visited(v,0);
    	vector<int> path_visited(v,0);
    	
    	for(int i=0 ; i<v ; i++)
    	{
    		if(!visited[i])
    		{
    			if(dfs(adj,visited,path_visited,i)==true) return true;
    		}
    	}
    	return false;
    }
};
