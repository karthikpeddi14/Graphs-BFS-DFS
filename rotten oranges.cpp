class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        queue<pair<int,int>> q;
        for(int i=0 ; i<n ; i++)
        {
            for(int j=0 ; j<m ; j++)
            {
                if(grid[i][j]==2) q.push({i,j}); 
            }
        }

        int min = 0;
        while(!q.empty())
        {
            int s = q.size();
            int add = 0;
            for(int i=0 ; i<s ; i++)
            {
                int a = q.front().first;
                int b = q.front().second;
                q.pop();
                if(a>0 && grid[a-1][b]==1)
                {
                    add++;
                    q.push({a-1,b});
                    grid[a-1][b] = 2;
                }
                if(a<n-1 && grid[a+1][b]==1)
                {
                    add++;
                    q.push({a+1,b});
                    grid[a+1][b] = 2;
                }
                if(b>0 && grid[a][b-1]==1)
                {
                    add++;
                    q.push({a,b-1});
                    grid[a][b-1] = 2;
                }
                if(b<m-1 && grid[a][b+1]==1)
                {
                    add++;
                    q.push({a,b+1});
                    grid[a][b+1] = 2;
                }
            }

            if(add>0) min++;
        }

        for(int i =0 ;i<n ; i++)
        {
            for(int j=0 ; j<m ; j++)
            {
                if(grid[i][j]==1) return -1;
            }
        }
        return min;
    }
};
