#include <bits/stdc++.h>

using namespace std;

int route[1002][1002];

queue<pair<int, int>> q;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int r, c;
    cin >> r >> c;
    pair<int, int> jihun;
    for(int i = 0; i<r; ++i)
    {
        string str;
        cin >> str;
        for(int j = 0; j<c; ++j)
        {
            if(str[j] == 'J')
            {
                jihun = make_pair(i, j);
                route[i][j] = 1;
            }
            else if(str[j] == 'F')
            {
                q.push({i, j});
                route[i][j] = -1;
            }
            else if(str[j] == '#')
                route[i][j] = -1;
        }
    }
    
    q.push(jihun);
    
    while(!q.empty())
    {
        auto cur = q.front();
        q.pop();
        
        for(int i = 0; i<4; ++i)
        {
            int newX = cur.first + dx[i];
            int newY = cur.second + dy[i];
            
            if(route[newX][newY] != 0) continue;
            if(route[cur.first][cur.second] >= 1)
            {
                if(newX < 0 || newY < 0 || newX >= r || newY >=c)   
                {
                    cout << route[cur.first][cur.second];
                    return 0;
                }
                route[newX][newY] = route[cur.first][cur.second]+1;
            }
            else
            {
                if(newX < 0 || newY < 0 || newX >= r || newY >=c) continue;
                route[newX][newY] = route[cur.first][cur.second];
            }
            q.push({newX, newY});
        }
    }
    
    cout << "IMPOSSIBLE";
}