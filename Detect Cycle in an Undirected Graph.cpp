class Graph {

public:
    bool detectCycle(int V, vector<int> adj[]) {
        queue<pair<int,int>> q;
        q.push({1,-1});
        vector<int> visited(V,0);

        while(!q.empty())
        {
            int a = q.front().first;
            int b = q.front().second;
            visited[a] = 1;
            q.pop(); 

            for(auto it:adj[a])
            {
                if(visited[it]==0) q.push({it,a});
                else if(it!=b) return true;
            }
        }
        return false;
    }
};
