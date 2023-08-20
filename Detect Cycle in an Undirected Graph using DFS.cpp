class Graph {

public:
    bool f(vector<int> adj[], int prev_index, int index, vector<int>& visited)
    {
        bool a = false;
        visited[index] = 1;
        for(auto it:adj[index])
        {
            if(visited[it]==0) a = a | f(adj,index,it,visited);
            else if(it!=prev_index) return true;
        }
        return a;
    }
    bool detectCycle(int V, vector<int> adj[]) {
        vector<int> visited(V,0);
        return f(adj,-1,1,visited);
    }
};
