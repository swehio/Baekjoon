#include <bits/stdc++.h>
using namespace std;

int arr1[1000002];
int arr2[1000002];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i<n; i++)
    {
        cin >> arr1[i];
        arr2[i] = arr1[i];
    }

    sort(arr2, arr2+n);

    
    
    int idx = 0;
    for(int i = 0; i<n-1; i++)
    {
        if(arr2[i+1] == arr2[i]) continue;
        arr2[idx++] = arr2[i];
    }

    arr2[idx++] = arr2[n-1];

    for(int i = 0; i<n; i++)
    {
        cout << lower_bound(arr2, arr2+idx, arr1[i]) - arr2 << ' ';
    }
    cout << '\n';
}