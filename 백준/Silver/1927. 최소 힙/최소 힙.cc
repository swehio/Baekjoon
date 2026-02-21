#include <bits/stdc++.h>
using namespace std; 


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); 

    priority_queue<int, vector<int>, greater<int>> pq;

    int n;
    cin >> n;

    while(n--)
    {
        int x;
        cin >> x;

        if(x==0)
        {
            if(!pq.empty()) 
            {
                cout << pq.top(); pq.pop();
            }
            else
            {
                cout << 0;
            } 
            cout << '\n';
        }
        else
        {
            pq.push(x);
        } 
    }

}