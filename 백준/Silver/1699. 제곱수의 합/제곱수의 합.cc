#include <bits/stdc++.h>

using namespace std;
int d[100002];
vector<int> pow_list;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    
    for(int i=1; i*i<=n; i++)
    {
        pow_list.push_back(i*i);
    }
    fill(d, d+n+1, 0xfffffff);
    d[0]=0;

    for(int i=1; i<=n; i++)
    {
        for(int pow_num : pow_list)
        {
            if(pow_num > i) break;
            d[i] = min(d[i], d[i-pow_num]+1);
        }
    }

    cout << d[n];
}