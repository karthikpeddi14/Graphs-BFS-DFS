// my method bfs
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();

        queue<pair<int,int>> q;
        vector<vector<int>> visited(n,vector<int>(m,0));
        q.push({sr,sc});

        while(!q.empty())
        {
            int a = q.front().first;
            int b = q.front().second;
            q.pop();
            visited[a][b] = 1;
            if(a>0 && image[a-1][b] == image[a][b] && visited[a-1][b]==0) q.push({a-1,b});
            if(b>0 && image[a][b-1] == image[a][b] && visited[a][b-1]==0) q.push({a,b-1});
            if(a<n-1 && image[a+1][b] == image[a][b] && visited[a+1][b]==0) q.push({a+1,b});
            if(b<m-1 && image[a][b+1] == image[a][b] && visited[a][b+1]==0) q.push({a,b+1});
            
            image[a][b] = color;
        }
        return image;
    }
};
// my method bfs

// my method dfs
class Solution {
public:
    void f(vector<vector<int>>& image, int a, int b , vector<vector<int>>& visited, int ini, int final)
    {
        if(visited[a][b]==1) return;
        visited[a][b]= 1;
        image[a][b] = final;
        int n = image.size();
        int m = image[0].size();
        
        if(a>0 && image[a-1][b] == ini) f(image,a-1,b,visited,ini,final);
        if(b>0 && image[a][b-1] == ini) f(image,a,b-1,visited,ini,final);
        if(a<n-1 && image[a+1][b] == ini) f(image,a+1,b,visited,ini,final);
        if(b<m-1 && image[a][b+1] == ini) f(image,a,b+1,visited,ini,final);

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();

        vector<vector<int>> visited(n,vector<int>(m,0));
        f(image,sr,sc,visited,image[sr][sc],color);
        return image;
    }
};
// using dfs
