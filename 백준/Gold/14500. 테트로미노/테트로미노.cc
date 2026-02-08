#include <bits/stdc++.h>
using namespace std;

int board[505][505];
vector<vector<pair<int, int>>> tetro;

bool isadj(pair<int, int>& a, pair<int, int>& b)
{
    if(a.first == b.first) return abs(a.second-b.second)==1;
    if(a.second == b.second) return abs(a.first-b.first)==1;
    return false;
}

bool isConnect(vector<pair<int, int>>& shape)
{
    bool flag = false;
    for(int i=0; i<4; i++)
    { 
        int cnt = 0;
        for(int j=0; j<4; j++)
        { 
            if(isadj(shape[i], shape[j])) cnt++;
        }
        if(cnt == 0) return false;
        if(cnt >= 2) flag = true; 
    }
    return flag;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
 
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin >> board[i][j];
        }
    }

    vector<int> brute(16);
    fill(brute.begin()+12, brute.end(), 1);

    do
    {
        vector<pair<int, int>> shape;
        for(int i=0; i<16; i++)
            if(brute[i]) shape.push_back({i/4, i%4});
        if(isConnect(shape)) tetro.push_back(shape);
    }while(next_permutation(brute.begin(), brute.end()));

    int mx = 0;
    for(int i=0; i<=n-4; i++)
    {
        for(int j=0; j<=m-4; j++)
        {
            for(auto shape : tetro)
            {
                int tot = 0;
                for(auto coor : shape)
                {
                    tot += board[i+coor.first][j+coor.second];
                }
                mx = max(mx, tot);
            }
        }
    }
    cout << mx;
}