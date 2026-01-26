#include <bits/stdc++.h>
using namespace std;

string board[1002];
int dis[1002][1002][2];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i=0; i<n; i++)
    { 
        cin >> board[i]; 
    }

    queue<tuple<int, int, int>> q;

    q.push({0, 0, 0});
    dis[0][0][0] = 1;
    while(!q.empty())
    {
        auto cur = q.front(); q.pop();

        for(int i=0; i<4; i++)
        {
            int x, y, w;
            tie(x, y, w) = cur;
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nw = w;

            if(nx<0||nx>=n||ny<0||ny>=m) continue;
            if(nw == 1 && board[nx][ny] == '1') continue;  
            if(board[nx][ny] == '1')  nw = 1; 
            if(dis[nx][ny][nw] != 0) continue;
            dis[nx][ny][nw]=dis[x][y][w]+1;
            q.push({nx, ny, nw}); 
        }
    } 

    if(dis[n-1][m-1][0] + dis[n-1][m-1][1] == 0) cout << -1;
    else if(dis[n-1][m-1][0] == 0 || dis[n-1][m-1][1] == 0) cout << dis[n-1][m-1][0] + dis[n-1][m-1][1];
    else cout << min(dis[n-1][m-1][0], dis[n-1][m-1][1]); 
}