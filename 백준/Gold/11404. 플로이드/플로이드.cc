#include <bits/stdc++.h>
using namespace std;
 
 const int INF = 0x3f3f3f3f;
int d[102][102];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(i==j) continue; 
            d[i][j]=INF;
        } 
    } 


    for(int i=1; i<=m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
 
        d[a][b] = min(d[a][b], c); 
    } 

    for(int k=1; k<=n; k++)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
            }
        } 
    }

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(d[i][j] != INF)
                cout << d[i][j] << ' ';
            else 
                cout << "0 ";
        }
        cout << '\n';
    } 
}