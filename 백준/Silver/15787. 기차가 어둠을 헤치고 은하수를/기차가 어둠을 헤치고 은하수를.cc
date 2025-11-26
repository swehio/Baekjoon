#include <bits/stdc++.h>
using namespace std; 

long long train[100002];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;

    long long reset = 0;
    for(int i=0; i<20; i++) reset += (1ll<<i);

    for(int i=0; i<m; i++)
    {
        int op, k, x;
        cin >> op >> k;
        
        if(op==1)
        {
            cin >> x;
            train[k-1] |= (1<<(x-1));
        }
        else if(op==2)
        {
            cin >> x;
            train[k-1] &= ~(1<<(x-1));
        }
        else if(op==3)
        {
            train[k-1]<<=1;
            train[k-1] &= reset;
        }
        else
        {
            train[k-1]>>=1;
        } 
    }

    set<long long> s;
    for(int i=0; i<n; i++)
    {
        s.insert(train[i]); 
    }
    cout << s.size();
}