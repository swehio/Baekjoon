#include <bits/stdc++.h>
using namespace std;

int N, M, st;
int result[10];
vector<int> arr;

bool compare(int a, int b)
{
    return a<b;
}

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
    for(int i = st; i<N; i++)
    {
        result[k] = arr[i];
        st=i+1;
        solve(k+1);
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
    
    sort(arr.begin(), arr.end(), compare);
    
    solve(0);
}