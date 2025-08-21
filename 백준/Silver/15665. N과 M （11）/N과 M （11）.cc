#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[10];
vector<int> num;

void solve(int k)
{
    if(k == M)
    {
        for(int i = 0; i<M; i++)
        {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }
    
    int temp = 0;
    for(int i = 0; i < N; i++)
    {
        if(temp != num[i])
        {
            arr[k] = num[i];
            temp = num[i];
            solve(k+1);
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
        int input;
        cin >> input;
        num.push_back(input);
    }
    
    sort(num.begin(), num.end());
    solve(0);
}