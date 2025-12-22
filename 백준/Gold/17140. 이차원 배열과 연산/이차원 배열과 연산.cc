#include <bits/stdc++.h>
using namespace std;

const int MX = 101;
int board[MX+2][MX+2];

int r, c, k;
int rc, cc;
int t;

void rcal()
{
    int cmx = cc;

    for(int i=0; i<rc; i++)
    {
        vector<pair<int, int>> v; // 등장 횟수, 수
        unordered_map<int, int> um; // 수, 등장 횟수
        for(int j=0; j<cc; j++)
        {
            if(board[i][j] == MX) continue;
            um[board[i][j]]++;
            board[i][j] = MX;
        }
        for(auto& cur : um)
        {
            v.push_back({cur.second, cur.first});
        }
        sort(v.begin(), v.end()); 

        vector<int> input; 
        for(int j=0; j<v.size(); j++)
        {
            input.push_back(v[j].second);
            input.push_back(v[j].first);
        }

        int size = input.size();
        for(int j=0; j<size; j++)
        {
            board[i][j] = input[j]; 
        }
        cmx = max(cmx, size);
    }
    cc = (cmx>100)? 100 : cmx;
}

void ccal()
{
    int rmx = rc;

    for(int i=0; i<cc; i++)
    {
        vector<pair<int, int>> v; // 등장 횟수, 수
        unordered_map<int, int> um;
        for(int j=0; j<rc; j++)
        {
            if(board[j][i] == MX) continue;
            um[board[j][i]]++;
            board[j][i] = MX;
        }
        for(auto& cur : um)
        {
            v.push_back({cur.second, cur.first});
        }
        sort(v.begin(), v.end()); 
 
        vector<int> input;
        for(int j=0; j<v.size(); j++)
        {
            input.push_back(v[j].second);
            input.push_back(v[j].first);
        }
        int size = input.size();
        for(int j=0; j<size; j++)
        {
            board[j][i] = input[j]; 
        }
        rmx = max(rmx, size);
    }
    rc = (rmx>100)? 100 : rmx;
}

void resize()
{
    for(int i=0; i<rc; i++)
    {
        for(int j=0; j<cc; j++)
        {
            if(board[i][j]<1) board[i][j] = MX;
        } 
    } 
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    cin >> r >> c >> k;
    r--;
    c--;

    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            cin >> board[i][j];

    rc = cc = 3;

    while(board[r][c] != k)
    {
        t++;
        if(t>100) 
        {
            cout << "-1";
            return 0;
        }
        if(rc >= cc) rcal();
        else ccal(); 

        resize();
    }

    cout << t;
}