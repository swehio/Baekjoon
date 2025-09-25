#include <bits/stdc++.h>
using namespace std;

int cnt;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    unordered_set<string> ids;

    string st, en, streamingEn;
    cin >> st >> en >> streamingEn;

    while(1)
    {
        string time, id;
        cin >> time >> id;
        if(cin.eof()) break;

        if(time <= st && time >= "00:00" ) 
        {
            ids.insert(id);
        }
        else if(time >= en && time <= streamingEn)
        {
            auto it = ids.find(id);
            if(it != ids.end())
            {
                cnt++;
                ids.erase(it);
            }
        }
    }

    cout << cnt;
}