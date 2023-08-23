class Solution {
public:
    bool dfs(vector<vector<int>>& graph, vector<int>& color, int col, int index)
    {
        color[index] = col;
        for(auto it:graph[index])
        {
            if(color[it]==-1)
            {
            if(dfs(graph,color,!col,it)==false) return false;
            }
            else if(color[it]==col) {
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n =graph.size();
        vector<int> color(n,-1);

        for(int i=0 ; i<n ; i++){
            if(color[i]==-1) 
            {
                if(dfs(graph,color,1,i)==false) return false;
            }
        }
        return true;
    }
};
