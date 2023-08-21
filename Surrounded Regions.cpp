// my method
class Solution {
public:
    void solve(vector<vector<char>>& board) 
    {
        int n = board.size();
        int m = board[0].size();
        queue<pair<int,int>> q;

        for(int i=0 ; i<n ; i++)
        {
            if(board[i][0]=='O') q.push({i,0});
            if(m!=1) if(board[i][m-1]=='O')  q.push({i,m-1});
        }

        for(int j=0 ; j<m ; j++)
        {
            if(board[0][j]=='O') q.push({0,j});
            if(n!=1 && board[n-1][j]=='O') q.push({n-1,j});
        }

        while(!q.empty())
        {
            int a = q.front().first;
            int b = q.front().second;
            board[a][b] = 'V';
            q.pop();

            if(a>0 && board[a-1][b]=='O') q.push({a-1,b});
            if(a<n-1 && board[a+1][b]=='O') q.push({a+1,b});
            if(b>0 && board[a][b-1]=='O') q.push({a,b-1});
            if(b<m-1 && board[a][b+1]=='O') q.push({a,b+1});
        }

        for(int i=0 ; i<n ; i++)
        {
            for(int j=0 ; j<m ; j++)
            {
                if(board[i][j]=='V') board[i][j] = 'O';
                else board[i][j] = 'X';
            }
        }
    }
}; 
