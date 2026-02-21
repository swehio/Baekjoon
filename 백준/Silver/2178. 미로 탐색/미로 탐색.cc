#include <bits/stdc++.h>
using namespace std; 

string board[102];
int dis[102][102];

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

    queue<pair<int, int>> q;
    q.push({0, 0});
    dis[0][0] = 1;

    while(!q.empty())
    {
        auto cur = q.front(); q.pop();

        for(int i=0; i<4; i++)
        {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if(nx<0||nx>=n||ny<0||ny>=m) continue;
            if(dis[nx][ny]!=0||board[nx][ny]=='0')continue;

            dis[nx][ny] = dis[cur.first][cur.second]+1;
            q.push({nx, ny});
        }
    } 

    cout << dis[n-1][m-1];
}