#include <bits/stdc++.h>
using namespace std;

int board[55][55];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int cnt;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, d;
    pair<int, int> cur;
    cin >> n >> m >> cur.first >> cur.second >> d;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin >> board[i][j];
        }
    }

    while(1)
    {
        if(board[cur.first][cur.second]==0)
        {
            board[cur.first][cur.second] = 2;
            cnt++;
        } 

        bool shouldClean = false;
  
        for(int i=0; i<4; i++)
        {  
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
  
            if(board[nx][ny] == 0) shouldClean = true;   
        }
        
        if(shouldClean)
        {
            d--;
            if(d<0) d=3;
            
            int nx = cur.first + dx[d];
            int ny = cur.second + dy[d];

            if(board[nx][ny] == 0) cur = {nx, ny};
        }
        else 
        {
            int nx = cur.first+(dx[d]==0?0:-dx[d]);
            int ny = cur.second+(dy[d]==0?0:-dy[d]);

            if(board[nx][ny] == 1) 
            {
                cout << cnt;
                return 0;
            }
            else cur = {nx, ny}; 
        }  

    }
}