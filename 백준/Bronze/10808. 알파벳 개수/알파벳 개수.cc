#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int SIZE = 'z'-'a' + 1;
    int arr[SIZE];
     
    for(int i = 0; i<SIZE; ++i) arr[i] = 0;
    
    string s;
    cin >> s;
    
    for(char ch : s)
    {
        ++arr[ch - 'a'];
    }
    
    for(int num : arr) cout << num << ' ';
}