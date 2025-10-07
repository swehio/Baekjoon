#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    int cnt = 0;

    queue<int> q;
    for(int i=1; i<=n; i++) q.push(i);

    cout << "<";
    while(!q.empty())
    {
        cnt++;
        int cur = q.front();
        q.pop();

        if(cnt == k) 
        {
            cnt = 0;
            cout << cur;
            if(q.size() != 0) cout << ", ";
            else 
            {
                cout << ">";
                break;
            }
        }
        else q.push(cur);
    }
}