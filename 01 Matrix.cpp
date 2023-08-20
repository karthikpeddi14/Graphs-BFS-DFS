class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) 
    {
        int n= mat.size();
        int m= mat[0].size();
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> visited(n,vector<int>(m,0));
        for(int i=0; i<n ; i++)
        {
            for(int j=0 ; j<m ; j++)
            {
                if(mat[i][j]==0) 
                {
                    q.push({{i,j},0});
                    visited[i][j] = 1;
                }
            }
        }

        vector<vector<int>> ans(n,vector<int>(m,0));
       
        while(!q.empty())
        {
            int s = q.size();
            for(int i=0 ; i<s ; i++)
            {
                int a = q.front().first.first;
                int b = q.front().first.second;
                int c = q.front().second;
                ans[a][b] = c;
                q.pop();

                if(a>0 && visited[a-1][b]!=1) 
                {
                    q.push({{a-1,b},c+1});
                    visited[a-1][b] = 1;
                }
                if(a<n-1 && visited[a+1][b]!=1) {
                    q.push({{a+1,b},c+1});
                    visited[a+1][b] = 1;
                }
                if(b>0 && visited[a][b-1]!=1){
                    q.push({{a,b-1},c+1});
                    visited[a][b-1] = 1;
                }
                if(b<m-1 && visited[a][b+1]!=1){
                    q.push({{a,b+1},c+1});
                    visited[a][b+1] = 1;
                }

            }
        }
        return ans;
    }
};
