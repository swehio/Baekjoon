#include <bits/stdc++.h>
using namespace std;

int arr[10002];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<int> v;
    
    while(n--)
    {
        int num;
        cin >> num;
        
        v.push_back(num);
    }
    
    sort(v.begin(), v.end(), [](int a, int b){return a>b;});
    
    for(int num : v)
    {
        cout << num <<'\n';
    }
}