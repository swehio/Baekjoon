#include<bits/stdc++.h>
using namespace std; 

string board[30];
int dis[30][30];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int n;
int num = 0;

int bfs(int a, int b)
{
    int cnt=1;

    queue<pair<int, int>> q;
    q.push({a, b});
    dis[a][b] = num;

    while(!q.empty())
    {
        auto cur = q.front(); q.pop();

        for(int i=0; i<4; i++)
        {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if(nx<0||nx>=n||ny<0||ny>=n) continue;
            if(dis[nx][ny]!=0||board[nx][ny]=='0')continue;

            dis[nx][ny]=num;
            q.push({nx, ny});
            cnt++;
        }
    }

    return cnt;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;

    for(int i=0; i<n; i++)
    {
        cin >> board[i];
    }

    vector<int> ans;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(board[i][j]=='1'&&dis[i][j]==0)
            {
                num++;
                int cnt = bfs(i, j);
                ans.push_back(cnt);
            }
        }
    }
    sort(ans.begin(), ans.end()); 
    
    cout << ans.size() << '\n';
    for(int cnt : ans) cout << cnt << '\n';
}