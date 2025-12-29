#include <bits/stdc++.h>
using namespace std;
vector<int> button;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int sum = 0;
    while(1)
    {
        int button;
        cin >> button;
        if(cin.eof()) break;

        if(button == 1) sum += 500;
        else if(button == 2) sum += 800;
        else sum += 1000;
    } 
 
    cout << 5000-(sum);
}