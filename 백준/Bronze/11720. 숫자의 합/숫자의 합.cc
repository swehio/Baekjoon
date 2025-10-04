#include <bits/stdc++.h>
using namespace std;

int line[3];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    string str;
    cin >> str;

    vector<int> v;

    int sum = 0;
    for(char ch : str) v.push_back(ch - '0');
    
    if(v.size() == n) sum = accumulate(v.begin(), v.end(), 0);
    else 
    {
        sum = accumulate(v.begin(), v.begin()+n-1, 0);
        sum += stoi(str.substr(n-1, str.size()-n+1));
    }
    cout << sum;
}