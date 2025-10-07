#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    
    while(t--)
    {
        int n, m;
        cin >> n >> m;

        queue<pair<int, int>> q;
        priority_queue<int> pq;

        for(int i=0; i<n; i++)
        {
            int num;
            cin >> num;
            q.push({num, i});
            pq.push(num);
        }

        int cnt = 0;

        while(!q.empty()&&!pq.empty())
        {
            auto cur = q.front();
            q.pop();
            if(cur.first == pq.top()) 
            {
                cnt++;
                if(cur.second == m) break;
                pq.pop();

            }
            else
            {
                q.push(cur);
            }
        }

        cout << cnt << '\n';
    }
}