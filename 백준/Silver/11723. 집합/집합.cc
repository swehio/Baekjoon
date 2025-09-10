#include <bits/stdc++.h>

int arr[20];

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int m;
    cin >> m;

    while(m--)
    {
        string op;
        cin >> op;

        if(op == "add")
        {
            int x;
            cin >> x;
            arr[x-1] = 1;
        }
        else if(op == "remove")
        {
            int x;
            cin >> x;
            arr[x-1] = 0;
        }
        else if(op == "check")
        {
            int x;
            cin >> x;
            cout << arr[x-1] << '\n';
        }
        else if(op == "toggle")
        {
            int x;
            cin >> x;
            if(arr[x-1] == 0) arr[x-1] = 1;
            else arr[x-1] = 0;
        }
        else if(op == "all")
        {
            for(int i=0; i<20; i++)
            {
                arr[i] = 1;
            }
        }
        else // empty
        {
            for(int i=0; i<20; i++)
            {
                arr[i] = 0;
            }
        }
    }
}