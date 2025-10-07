#include <bits/stdc++.h>

using namespace std;

pair<int, int> people[55];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    for(int i=0; i<t; i++) cin >> people[i].first >> people[i].second; 

    for(int i=0; i<t; i++)
    {
        int cnt = 0;
        for(int j=0; j<t; j++)
        {
            if(i == j) continue;
            if((people[i].first < people[j].first) && (people[i].second < people[j].second)) cnt++;
        }
        cout << cnt+1 << ' ';
    }
}