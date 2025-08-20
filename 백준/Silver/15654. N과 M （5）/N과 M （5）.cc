#include <bits/stdc++.h>
using namespace std;

int N, M;
int result[10];
int isused[10];
vector<int> arr;

void solve(int k)
{
    if(k == M)
    {
        for(int i = 0; i < M; i++)
        {
            cout << result[i] << ' ';
        }
        cout << '\n';
        return;
    }
    
    for(int i = 0; i<N; i++)
    {
        if(!isused[i])
        {
            result[k] = arr[i];
            isused[i] = 1;
            solve(k+1);
            isused[i] = 0;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;
    
    for(int i = 0; i<N; i++)
    {
        int num;
        cin >> num;
        arr.push_back(num);
    }
    
    sort(arr.begin(), arr.end());
    
    solve(0);
}