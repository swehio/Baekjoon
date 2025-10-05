#include <bits/stdc++.h>
using namespace std;

long long cachePow[55];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(1)
    {
        string num;
        cin >> num;
        if(num == "0") break;

        bool isPelindrom = true;

        for(int i=0; i*i<=num.size(); i++)
        {
            if(num[i] != num[num.size()-1-i])
            {
                isPelindrom = false;
                break;
            }
        }

        cout << (isPelindrom ? "yes" : "no") << '\n';
    }
}