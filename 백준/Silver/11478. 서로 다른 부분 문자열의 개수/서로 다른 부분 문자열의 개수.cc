#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    unordered_map<string, string> nameToTeam;
    unordered_map<string, vector<string>> teamToName;

    string str;
    cin >> str;

    unordered_set<string> substrs;

    for(int i=0; i<str.size(); i++)
    {
        for(int j=0; j<str.size()-i; j++)
        {
            substrs.insert(str.substr(j, i+1));
        }
    }

    cout << substrs.size();
}