#include <bits/stdc++.h>
using namespace std;

const int MAX = 5;
int board[MAX*2][MAX*2][MAX*2];
int tmpb[MAX*2][MAX*2][MAX*2];

int dis[MAX*2][MAX*2][MAX*2];

int dx[] = {1, -1, 0, 0, 0, 0};
int dy[] = {0, 0, 1, -1, 0, 0};
int dz[] = {0, 0, 0, 0, 1, -1};

tuple<int, int, int> st[] = {{0, 0, 0}, {0, 0, 4}, {0, 4, 0}, {0, 4, 4}};
tuple<int, int, int> en[] = {{4, 4, 4}, {4, 4, 0}, {4, 0, 4}, {4, 0, 0}};

void rotate(int k, int dir)
{
    int tmpr[MAX][MAX];
    for(int i=0; i<MAX; i++)
    {
        for(int j=0; j<MAX; j++) 
        {
            tmpr[i][j] = tmpb[k][i][j];
        }
    }
    for(int i=0; i<MAX; i++)
    {
        for(int j=0; j<MAX; j++) 
        {
            tmpb[k][i][j] = tmpr[MAX-1-j][i];
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int k=0; k<MAX; k++)
    {
        for(int i=0; i<MAX; i++)
        {
            for(int j=0; j<MAX; j++)
            {
                cin >> board[k][i][j];
            }
        } 
    }

    int nums[] = {0,1,2,3,4};

    int mn = 0xfffffff;
    do
    {
        for(int i=0; i<MAX; i++)
        {
            memcpy(tmpb[i], board[nums[i]], sizeof(board[i]));
        }


        for(int tmp=0; tmp<(1<<(2*MAX)); tmp++)
        {
            int brute = tmp;
            for(int i=0; i<MAX; i++)
            {
                int dir = brute%4;
                brute/=4;

                 while(dir--)
                    rotate(i, dir);  
            } 

            for(int k=0; k<4; k++)
            {
                for(int i=0; i<MAX; i++)
                {
                    for(int j=0; j<MAX; j++)
                        fill(dis[i][j], dis[i][j]+MAX, -1);
                }
                int x, y, z;
                tie(x, y, z) = st[k];

                if(tmpb[x][y][z] == 0) continue;

                queue<tuple<int, int, int>> q;
                q.push(st[k]);

                dis[x][y][z] = 0;

                while(!q.empty())
                {
                    auto cur = q.front(); q.pop();

                    for(int i=0; i<6; i++)
                    {
                        int nx = get<0>(cur) + dx[i];
                        int ny = get<1>(cur) + dy[i];
                        int nz = get<2>(cur) + dz[i];

                        if(nx<0||nx>=MAX||ny<0||ny>=MAX||nz<0||nz>=MAX) continue;
                        if(dis[nx][ny][nz] != -1||tmpb[nx][ny][nz] == 0) continue;

                        dis[nx][ny][nz] = dis[get<0>(cur)][get<1>(cur)][get<2>(cur)]+1;
                        q.push({nx, ny, nz}); 
                    }
                }

                if(dis[get<0>(en[k])][get<1>(en[k])][get<2>(en[k])] != -1) 
                    mn = min(mn, dis[get<0>(en[k])][get<1>(en[k])][get<2>(en[k])]);
            }
 
        }   
    }while(next_permutation(nums, nums+5));

    if(mn == 0xfffffff) cout << "-1";
    else cout << mn;
}