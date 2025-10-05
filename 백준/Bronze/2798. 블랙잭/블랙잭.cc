#include <bits/stdc++.h>
using namespace std;

int arr[102];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i=0; i<n; i++) cin >> arr[i];
    set<int> s;

    for(int i=0; i<n-2; i++)
    {
        for(int j=i+1; j<n-1; j++)
        {
            for(int k=j+1; k<n; k++)
            {
                s.insert((arr[i]+arr[j]+arr[k]));
            }
        }
    }

    auto it = upper_bound(s.begin(), s.end(), m);
    cout << *(prev(it));
}